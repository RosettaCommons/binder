// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/function.cpp
/// @brief  Binding generation for static and member functions
/// @author Sergey Lyskov

#include <function.hpp>
#include <options.hpp>

#include <class.hpp>
#include <fmt/format.h>
#include <type.hpp>
#include <util.hpp>

#include <clang/AST/ASTContext.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/Type.h>

#include <clang/AST/ExprCXX.h>

// #include <tsl/robin_map.h>

#include <vector>

using llvm::errs;
using llvm::outs;

using namespace llvm;
using namespace clang;

using std::pair;
using std::string;
using std::tuple;
using std::unordered_map;
using std::vector;

using namespace fmt::literals;

namespace binder {

// Return the python operator that maps to the C++ operator; returns "" if no mapping exists
// This correctly handles operators that have multiple meanings depending on their argument count
// For example, operator_(this, other) maps to __sub__ while operator-(this) maps to __neg__
string cpp_python_operator(const FunctionDecl &F)
{
	static std::map<string, vector<string>> const m{
		{"operator+", {"__pos__", "__add__"}}, //
		{"operator-", {"__neg__", "__sub__"}}, //
		{"operator*", {"dereference", "__mul__"}}, //
		{"operator/", {"__truediv__"}}, //
		{"operator%", {"__mod__"}}, //
		{"operator~", {"__invert__"}}, //
		{"operator|", {"__or__"}}, //
		{"operator&", {"__and__"}}, //
		{"operator^", {"__xor__"}}, //
		{"operator<<", {"__lshift__"}}, //
		{"operator>>", {"__rshift__"}}, //

		{"operator+=", {"__iadd__"}}, //
		{"operator-=", {"__isub__"}}, //
		{"operator*=", {"__imul__"}}, //
		{"operator/=", {"__itruediv__"}}, //
		{"operator%=", {"__imod__"}}, //
		{"operator|=", {"__ior__"}}, //
		{"operator&=", {"__iand__"}}, //
		{"operator^=", {"__ixor__"}}, //
		{"operator<<=", {"__ilshift__"}}, //
		{"operator>>=", {"__irshift__"}}, //

		{"operator()", {"__call__"}}, //
		{"operator==", {"__eq__"}}, //
		{"operator!=", {"__ne__"}}, //
		{"operator[]", {"__getitem__"}}, //
		{"operator=", {"assign"}}, //
		{"operator++", {"pre_increment", "post_increment"}}, //
		{"operator--", {"pre_decrement", "post_decrement"}}, //

		{"operator->", {"arrow"}} //
	};
	const auto &found = m.find(F.getNameAsString());
	if( found != m.end() ) {
		const auto &vec = found->second;
		const auto n = F.getNumParams();
		return n < vec.size() ? vec[n] : vec.back();
	}
	return {};
}


// Generate function argument list separate by comma: int, bool, std::string
string function_arguments(clang::FunctionDecl const *record)
{
	string r;

	for( uint i = 0; i < record->getNumParams(); ++i ) {
		// r += standard_name(record->getParamDecl(i)->getOriginalType().getCanonicalType().getAsString());
		r += standard_name(record->getParamDecl(i)->getOriginalType());
		if( i + 1 != record->getNumParams() ) r += ", ";
	}

	fix_boolean_types(r);

	return r;
}


// Generate function argument list separate by comma
// name_arguments - if arguments should be named: a1, a2, ...
// n - number of arguments to generate. If n > num_of_function_parameters - generate only list with num_of_function_parameters
pair<string, string> function_arguments_for_lambda(clang::FunctionDecl const *record, uint n)
{
	string r, a;

	for( uint i = 0; i < record->getNumParams() and i < n; ++i ) {
		QualType qt = record->getParamDecl(i)->getOriginalType();
		r += standard_name(qt) + ' ';
		if( !qt->isReferenceType() and !qt->isPointerType() ) r += !qt.isConstQualified() ? "const & " : "& ";
		r += "a" + std::to_string(i);
		a += "a" + std::to_string(i);
		if( i + 1 != record->getNumParams() and i + 1 != n ) {
			r += ", ";
			a += ", ";
		}
	}

	fix_boolean_types(r);

	// outs() << r << " ____ " << a << '\n';
	return std::make_pair(r, a);
}


// Generate three version of function argument list: (with types separate by comma, only arguments names, only argument names with by-reference arguments converted to pointers by adding '&'
// example: ("string const & a0, int *a1, float a2", "a0, a1, a2", "&a0, a1, a2")
tuple<string, string, string> function_arguments_for_py_overload(clang::FunctionDecl const *record)
{
	string r, a, p;

	for( uint i = 0; i < record->getNumParams(); ++i ) {
		QualType qt = record->getParamDecl(i)->getOriginalType();
		r += standard_name(qt) + ' ' + "a" + std::to_string(i);
		a += "a" + std::to_string(i);
		p += string(qt->isLValueReferenceType() ? "&" : "") + "a" + std::to_string(i);
		if( i + 1 != record->getNumParams() ) {
			r += ", ";
			a += ", ";
			p += ", ";
		}
	}

	fix_boolean_types(r);

	return std::make_tuple(r, a, p);
}


// generate class template specialization for ClassTemplateSpecializationDecl or empty string otherwise
string template_specialization(FunctionDecl const *F)
{
	string templ;

	if( F->getTemplatedKind() == FunctionDecl::TK_MemberSpecialization or F->getTemplatedKind() == FunctionDecl::TK_FunctionTemplateSpecialization ) {
		// TemplateArgumentList const *master = nullptr;
		// if( FunctionTemplateDecl const *fdc = F->getDescribedFunctionTemplate() ) {
		// 	//F->dump();
		// 	if( FunctionDecl const *td = fdc->getTemplatedDecl() ) {
		// 		//td->dump();
		// 	}
		// }

		// ArrayRef< TemplateArgument > args;

		// if( FunctionTemplateDecl *fdc = F->getPrimaryTemplate() ) {
		//  	outs() << "master for: " << F->getNameAsString() << "\n";
		// 	args = fdc->getInjectedTemplateArgs();
		// 	for(auto a = args.begin(); a != args.end(); ++a) {
		// 		outs() << "  function template argument: " << template_argument_to_string( *a ) << " type:" << a->getKind() <<  " :" << a->isDependent() << " :" << a->isInstantiationDependent() <<
		// "\n";
		// 	}
		// }

		// if( FunctionDecl const *master = F->getTemplateInstantiationPattern() ) {
		// 	outs() << "master for: " << F->getNameAsString() << "\n";
		// 	if( TemplateArgumentList const *ta = F->getTemplateSpecializationArgs() ) {
		// 		for(uint i=0; i < ta->size(); ++i) {
		// 			string arg = template_argument_to_string( ta->get(i) );
		// 			outs() << arg << " kind: " << ta->get(i).getKind()  << "\n";
		// 		}
		// 	}
		// }

		if( TemplateArgumentList const *ta = F->getTemplateSpecializationArgs() ) {

			templ += "<";
			for( uint i = 0; i < ta->size(); ++i ) {
				// if( ta->get(i).getKind() != TemplateArgument::ArgKind::Null ) {
				// outs() << "function: '" << F->getNameAsString() << "' template argument[" << i << "]=" << template_argument_to_string( ta->get(i) ) << " kind:" << ta->get(i).getKind() << "\n";

				// if( ta->get(i).isDependent() ) break;  // avoid explicitly specifying SFINAE related arguments
				// if( ta->get(i).getKind() == TemplateArgument::Expression ) break;  // avoid explicitly specifying SFINAE related arguments

				if( ta->get(i).getKind() == TemplateArgument::ArgKind::Pack and !ta->get(i).pack_size() ) continue; // skipping `<>` at the end of parameter packs

				string arg = template_argument_to_string(ta->get(i));
				if( ta->get(i).getKind() == TemplateArgument::ArgKind::Pack and arg.size() > 2 ) arg = arg.substr(1, arg.size() - 2); // removing extra <> around template parameter pack
				templ += arg + ",";

				// outs() << arg << " kind: " << ta->get(i).getKind()  << "\n";

				// if( t->getTemplateArgs()[i].ArgKind() == TemplateArgument::ArgKind::Integral ) outs() << " template arg:" << t->getTemplateArgs()[i].<< "\n";
				// outs() << expresion_to_string( t->getTemplateArgs()[i].getAsExpr() ) << "\n";
			}
			templ.back() = '>';
			if( templ.size() == 1 ) templ.resize(0); // case for `<>`

			fix_boolean_types(templ);
		}
	}

	return standard_name(templ);
}


// generate string represetiong class name that could be used in python
string python_function_name(FunctionDecl const *F)
{
	if( F->isOverloadedOperator() ) { return cpp_python_operator(*F); }
	else {
		// if( auto m = dyn_cast<CXXMethodDecl>(F) ) {
		// }
		// else{
		// 	if( F->getTemplatedKind() == FunctionDecl::TK_MemberSpecialization  or   F->getTemplatedKind() == FunctionDecl::TK_FunctionTemplateSpecialization ) outs() << namespace_from_named_decl(F)
		// << "::" << F->getNameAsString() << "\n";
		// }

		// there is no point of generating different names for different template function since in most cases we can treat them as overload's
		// return mangle_type_name( F->getNameAsString() + template_specialization(F) );
		return F->getNameAsString();
	}
}

// Generate function pointer type string for given function: void (*)(int, doule)_ or  void (ClassName::*)(int, doule)_ for memeber function
string function_pointer_type(FunctionDecl const *F)
{
	// F->dump();
	string r;
	string prefix, maybe_const;
	if( auto m = dyn_cast<CXXMethodDecl>(F) ) {
		prefix = m->isStatic() ? "" : class_qualified_name(cast<CXXRecordDecl>(F->getParent())) + "::";
		maybe_const = m->isConst() ? " const" : "";
	}

	// r += standard_name(F->getReturnType().getCanonicalType().getAsString());
	r += standard_name(F->getReturnType());

	r += " ({}*)("_format(prefix);

	r += function_arguments(F);

	r += ")" + maybe_const;

	fix_boolean_types(r);

	return r; // standard_name(r) call moved to function_arguments
}


// generate qualified function name that could be used in bindings code indcluding template specialization if any
string function_qualified_name(FunctionDecl const *F, bool omit_return_type)
{
	string maybe_const;
	if( auto m = dyn_cast<CXXMethodDecl>(F) ) maybe_const = m->isConst() ? " const" : "";

	string r =
		(omit_return_type ? "" : standard_name(F->getReturnType()) + " ") + standard_name(F->getQualifiedNameAsString() + template_specialization(F)) + "(" + function_arguments(F) + ")" + maybe_const;

	fix_boolean_types(r);
	return r;
}

/// generate human redable C++ type signature for given function
// string function_type_signature(FunctionDecl const *F)
// {
// 	return "C++: " + F->getQualifiedNameAsString() + "(" + function_arguments(F) + ')' + (F->isConst() ? " const" : "") + " --> " + standard_name( F->getReturnType().getCanonicalType().getAsString() )
// + '\n';
// }


// generate vector<QualType> with all types that function uses including: return type, types of function arguments and template arguments
vector<QualType> get_type_dependencies(FunctionDecl const *F)
{
	vector<QualType> r;

	r.push_back(F->getReturnType()); //.getDesugaredType(F->getASTContext()) );
	for( uint i = 0; i < F->getNumParams(); ++i ) r.push_back(F->getParamDecl(i)->getOriginalType() /*.getDesugaredType(F->getASTContext())*/);

	// if( F->getTemplatedKind() == FunctionDecl::TK_MemberSpecialization  or   F->getTemplatedKind() == FunctionDecl::TK_FunctionTemplateSpecialization ) {
	if( F->getTemplatedKind() != FunctionDecl::TK_NonTemplate ) {
		if( TemplateArgumentList const *tal = F->getTemplateSpecializationArgs() ) {
			for( uint i = 0; i < tal->size(); ++i ) {
				TemplateArgument const &ta(tal->get(i));
				if( ta.getKind() == TemplateArgument::Type ) r.push_back(ta.getAsType());
			}
		}
	}

	return r;
}


/// check if user requested binding for the given declaration
bool is_binding_requested(FunctionDecl const *F, Config const &config)
{
	if( config.is_function_binding_requested(F->getQualifiedNameAsString()) or config.is_function_binding_requested(function_qualified_name(F, true)) ) return true;

	bool bind = config.is_namespace_binding_requested(namespace_from_named_decl(F));

	for( auto &t : get_type_dependencies(F) ) bind |= binder::is_binding_requested(t, config);

	return bind;
}


/// check if user requested skipping for the given declaration
bool is_skipping_requested(FunctionDecl const *F, Config const &config)
{
	string qualified_name = standard_name(F->getQualifiedNameAsString());
	string qualified_name_with_args_info_and_template_specialization = function_qualified_name(F, true);

	if( config.is_function_skipping_requested(qualified_name_with_args_info_and_template_specialization) )
		return true; // qualified function name + parameter and template info was requested for skipping
	if( config.is_function_binding_requested(qualified_name_with_args_info_and_template_specialization) )
		return false; // qualified function name + parameter and template info was requested for binding

	if( config.is_function_skipping_requested(qualified_name) ) return true; // qualified function name was requested for skipping
	if( config.is_function_binding_requested(qualified_name) ) return false; // qualified function name was requested for binding

	bool skip = config.is_namespace_skipping_requested(namespace_from_named_decl(F));

	// moved to config -> qualified_name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
	skip |= config.is_function_skipping_requested(qualified_name);

	// calculating skipping for template classes without template specialization specified as: myclass::member_function_to_skip
	// outs() << "Checking skipping for function: " << function_qualified_name(F, true) << "...\n";

	if( CXXMethodDecl const *M = dyn_cast<CXXMethodDecl>(F) ) {
		CXXRecordDecl const *C = M->getParent();
		if( dyn_cast<ClassTemplateSpecializationDecl>(C) ) {
			// outs() << C->getQualifiedNameAsString() << "::" << F->getNameAsString() << "\n";
			skip |= config.is_function_skipping_requested(standard_name(C->getQualifiedNameAsString() + "::" + F->getNameAsString()));
		}
	}
	// outs() << "OK\n";

	for( auto &t : get_type_dependencies(F) ) skip |= is_skipping_requested(t, config);

	return skip;
}


/// Returns whether F is an overloaded assignment operator (operator= or any of the compound assigns)
bool is_valid_assignment_operator(const clang::FunctionDecl *F)
{
	// For any of the assignment operators (operator= or any of the compound assigns), we declare it to be a valid (typical) assignment operator if it is declared as a non-static member, taking
	// exactly one parameter, and returning an lvalue reference to the class type itself. In that case, we want to apply a specialized default return value policy to it.

	// Must be a non‑static C++ member function
	auto *m = dyn_cast<clang::CXXMethodDecl>(F);
	if( !m || m->isStatic() ) return false;

	// Must be an overloaded operator
	if( !m->isOverloadedOperator() ) return false;

	// Only accept assignment & compound‑assignment operators
	using Op = clang::OverloadedOperatorKind;
	switch( m->getOverloadedOperator() ) {
	case Op::OO_Equal: // operator=
	case Op::OO_PlusEqual: // operator+=
	case Op::OO_MinusEqual: // operator-=
	case Op::OO_StarEqual: // operator*=
	case Op::OO_SlashEqual: // operator/=
	case Op::OO_PercentEqual: // operator%=
	case Op::OO_LessLessEqual: // operator<<=
	case Op::OO_GreaterGreaterEqual: // operator>>=
	case Op::OO_AmpEqual: // operator&=
	case Op::OO_PipeEqual: // operator|=
	case Op::OO_CaretEqual: // operator^=
		break;
	default:
		return false;
	}

	// Must take exactly one argument
	if( m->getNumParams() != 1 ) return false;

	// Return type must be an lvalue reference
	clang::QualType ret_ty = m->getReturnType();
	if( !ret_ty->isLValueReferenceType() ) return false;

	// The referenced type must be the class’s own type
	clang::QualType pointeeTy = ret_ty->getPointeeType().getCanonicalType();
	clang::ASTContext &Ctx = m->getASTContext();
	clang::QualType classTy = Ctx.getRecordType(m->getParent()).getCanonicalType();
	if( !Ctx.hasSameType(pointeeTy, classTy) ) return false;

	return true;
}


/// get the return value policy string for a function
std::string get_rv_policy_for_function(clang::FunctionDecl const *F, Config const &config)
{
	// Prepare the return value policy string, and a string noting which type of function we are dealing with (for user output).
	string rvp_result = "";

	// We generally go from most generic to most specific way of specifying custom rv policies here.
	// First, check if any default return value policy is applicable. This also tells us if the function needs an rv policy to begin with.
	CXXMethodDecl const *m = dyn_cast<CXXMethodDecl>(F);
	if( is_valid_assignment_operator(F) && !config.default_member_assignment_operator_return_value_policy().empty() ) {
		rvp_result = ", " + config.default_member_assignment_operator_return_value_policy();
	}
	else if( m and !m->isStatic() ) {
		// Member functions
		if( F->getReturnType()->isPointerType() ) {
			rvp_result = ", " + config.default_member_pointer_return_value_policy();
		}
		else if( F->getReturnType()->isLValueReferenceType() ) {
			rvp_result = ", " + config.default_member_lvalue_reference_return_value_policy();
		}
		else if( F->getReturnType()->isRValueReferenceType() ) {
			rvp_result = ", " + config.default_member_rvalue_reference_return_value_policy();
		}
	}
	else if( m and m->isStatic() ) {
		// Static member functions
		if( F->getReturnType()->isPointerType() ) {
			rvp_result = ", " + config.default_static_pointer_return_value_policy();
		}
		else if( F->getReturnType()->isLValueReferenceType() ) {
			rvp_result = ", " + config.default_static_lvalue_reference_return_value_policy();
		}
		else if( F->getReturnType()->isRValueReferenceType() ) {
			rvp_result = ", " + config.default_static_rvalue_reference_return_value_policy();
		}
	}
	else {
		// Free functions
		if( F->getReturnType()->isPointerType() ) {
			rvp_result = ", " + config.default_function_pointer_return_value_policy();
		}
		else if( F->getReturnType()->isLValueReferenceType() ) {
			rvp_result = ", " + config.default_function_lvalue_reference_return_value_policy();
		}
		else if( F->getReturnType()->isRValueReferenceType() ) {
			rvp_result = ", " + config.default_function_rvalue_reference_return_value_policy();
		}
	}

	// If no rv policy was set, then the function does not need one, so we skip all custom ones.
	if( rvp_result.empty() ) {
		return rvp_result;
	}
	string custom_rvp;
	bool uses_custom_rvp = false;

	// Now check if there is a policy set for the whole class (if the function belongs to one).
	// We first check if there is a custom rv policy for the specific class instantiation, and if not, also check if there is one for the class name without template arguments.
	if( m ) {
		auto C = m->getParent(); // the CXXRecordDecl that the function belongs to
		string const qualified_name_without_template = standard_name(C->getQualifiedNameAsString());
		custom_rvp = config.get_return_value_policy_for_class( qualified_name_without_template );
		if( !custom_rvp.empty() ) {
			rvp_result = ", " + custom_rvp;
			uses_custom_rvp = true;
		}
		string const qualified_name = class_qualified_name(C);
		custom_rvp = config.get_return_value_policy_for_class( qualified_name );
		if( !custom_rvp.empty() ) {
			rvp_result = ", " + custom_rvp;
			uses_custom_rvp = true;
		}
	}

	// Now we get more specific and look for the particular function, overriding any previous results if we find something.
	// Check if there is a custom rv policy for this function (for its general and specialized names, such that fully specified names have precedence over qualified names).
	string const qualified_name = standard_name(F->getQualifiedNameAsString());
	custom_rvp = config.get_return_value_policy(qualified_name);
	if( !custom_rvp.empty() ) {
		rvp_result = ", " + custom_rvp;
		uses_custom_rvp = true;
	}
	string const qualified_name_with_args_info_and_template_specialization = function_qualified_name(F, true);
	custom_rvp = config.get_return_value_policy(qualified_name_with_args_info_and_template_specialization);
	if( !custom_rvp.empty() ) {
		rvp_result = ", " + custom_rvp;
		uses_custom_rvp = true;
	}

	// In verbose mode, we print functions that use the default rv policy, to allow devs to quickly identify them and check if they need customization in the config.
	// This is not printed for assignment operators (where rvp_name is left empty), as we assume this to be a special case where we are always okay using the default, as it has to be set
	// explicitly in the config.
	if( !uses_custom_rvp ) {
		if( O_verbose ) outs() << "Function " << qualified_name_with_args_info_and_template_specialization << " uses default return value policy\n";
	}

	return rvp_result;
}


// Generate binding for given function: .def("foo", (std::string (aaaa::A::*)(int) ) &aaaa::A::foo, "doc")
string bind_function(FunctionDecl const *F, uint args_to_bind, bool request_bindings_f, Context &context, CXXRecordDecl const *parent, bool always_use_lambda)
{
	string function_name = python_function_name(F);

	string function_qualified_name = standard_name(parent ? class_qualified_name(parent) + "::" + F->getNameAsString() : F->getQualifiedNameAsString());

	CXXMethodDecl const *m = dyn_cast<CXXMethodDecl>(F);

	string maybe_static;
	if( m and m->isStatic() ) {
		maybe_static = "_static";
		function_name = Config::get().prefix_for_static_member_functions() + function_name;
		// outs() << "STATIC: " << function_qualified_name << " → " << function_name << "\n";
	}

	string function, documentation;
	if( args_to_bind == F->getNumParams() and (not always_use_lambda) ) {
		function = "({}) &{}{}"_format(function_pointer_type(F), function_qualified_name, template_specialization(F));

		documentation = generate_documentation_string_for_declaration(F);
		if( documentation.size() ) documentation += "\\n\\n";
		documentation +=
			"C++: " + standard_name(F->getQualifiedNameAsString() + "(" + function_arguments(F) + ')' + (m and m->isConst() ? " const" : "") + " --> " + standard_name(F->getReturnType()));
	}
	else {
		pair<string, string> args = function_arguments_for_lambda(F, args_to_bind);
		// string args; for(uint i=0; i<args_to_bind; ++i) args += "a" + std::to_string(i) + ( i+1 == args_to_bind ? "" : ", " );

		string return_type = standard_name(F->getReturnType());

		// workaround of GCC bug during lambda specification: replace enum/struct/class/const_* from begining of the lambda return type with //const*
		static vector< std::pair<string, string> > const name_map = {
			std::make_pair("enum ", ""),
			std::make_pair("class ", ""),
			std::make_pair("struct ", ""),
			std::make_pair("const enum ", "const "),
			std::make_pair("const class ", "const "),
			std::make_pair("const struct ", "const "),
		};
		for( auto &p : name_map ) {
			if( begins_with(return_type, p.first) ) { return_type = p.second + return_type.substr(p.first.size()); }
		}

		if( m and !m->isStatic() ) {
			// string object = class_qualified_name( m->getParent() ) + (m->isConst() ? " const" : "") + " &o" + ( args_to_bind ? ", " : "" );
			string object = class_qualified_name(parent ? parent : m->getParent()) + (m->isConst() ? " const" : "") + " &o" +
							(args_to_bind ? ", " : ""); // forcing object type to be of parent class so member function with lifted access could be used
			function = "[]({}{}) -> {} {{ return o.{}({}); }}"_format(object, args.first, return_type, F->getNameAsString(), args.second);
		}
		else {
			function = "[]({}) -> {} {{ return {}({}); }}"_format(args.first, return_type, function_qualified_name, args.second);
		}
	}

	// Get the return value policy for the function, or empty if not needed.
	string const maybe_return_policy = get_rv_policy_for_function(F, Config::get());

	// string r = R"(.def{}("{}", ({}) &{}{}, "doc")"_format(maybe_static, function_name, function_pointer_type(F), function_qualified_name, template_specialization(F));
	string r = R"(.def{}("{}", {}, "{}"{})"_format(maybe_static, function_name, function, documentation, maybe_return_policy);

	if( request_bindings_f ) request_bindings(F->getReturnType().getCanonicalType(), context);

	for( uint i = 0; i < F->getNumParams() and i < args_to_bind; ++i ) {
		r += ", pybind11::arg(\"{}\")"_format(string(F->getParamDecl(i)->getName()));

		if( request_bindings_f ) request_bindings(F->getParamDecl(i)->getOriginalType(), context);
	}

	if( !Config::get().default_call_guard().empty() ) r += ", pybind11::call_guard<" + Config::get().default_call_guard() + ">()";

	r += ");";

	return r;
}


// Generate binding for given function. If function have default arguments generate set of bindings by creating separate bindings for each argument with default.
// if parent is not nullptr then bind function as-if it a member of that CXXRecordDecl (for handling visibility changes with 'using' directive)
string bind_function(string const &module, FunctionDecl const *F, Context &context, CXXRecordDecl const *parent, bool always_use_lambda)
{
	string code;

	if( O_annotate_functions ) {
		string const include = relevant_include(F);
		code += "\t// function-signature: " + function_qualified_name(F) + "(" + function_arguments(F) + ") file:" + (include.size() ? include.substr(1, include.size() - 2) : "") +
				" line:" + line_number(F) + "\n";
	}

	int num_params = F->getNumParams();

	int args_to_bind = 0;

	for( int i = 0; i < num_params; ++i ) {
		// we want to avoid generating any lambda expression when any of the function arguments have function-type
		if( is_function_type(F->getParamDecl(i)->getOriginalType().getCanonicalType()) ) {
			args_to_bind = num_params;
			break;
		}
	}

	for( ; args_to_bind < num_params; ++args_to_bind ) {
		if( F->getParamDecl(args_to_bind)->hasDefaultArg() ) break;
	}

	for( ; args_to_bind <= num_params; ++args_to_bind ) code += module + bind_function(F, args_to_bind, args_to_bind == num_params, context, parent, always_use_lambda or F->isVariadic()) + '\n';

	return code;
}


/// extract include needed for this generator and add it to includes vector
void add_relevant_includes(FunctionDecl const *F, IncludeSet &includes, int level /*, bool for_template_arg_only*/)
{
	if( !includes.add_decl(F, level) ) return;

	add_relevant_include_for_decl(F, includes);

	for( auto &t : get_type_dependencies(F) ) binder::add_relevant_includes(t, includes, level);
}


/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
string FunctionBinder::id() const
{
	return function_qualified_name(F);
}


/// check if generator can create binding
bool is_bindable_raw(FunctionDecl const *F)
{
	// outs() << "is_bindable: " << F->getQualifiedNameAsString() << "\n";
	// if( F->getQualifiedNameAsString() == "utility::foo" ) {
	// 	//outs() << "FunctionDecl::TK_FunctionTemplate: " << F->getQualifiedNameAsString() << "\n";
	// 	F->dump();
	// }

	// check for functions in anonymous namespaces
	// if( F->getQualifiedNameAsString().rfind(')') != std::string::npos ) return false;
	auto qualified_name = F->getQualifiedNameAsString();
	auto closing_bracket = qualified_name.rfind(')');
	if( closing_bracket != std::string::npos ) {
		if( closing_bracket > 0 and qualified_name[closing_bracket - 1] == '(' ) {} // operator()
		else return false;
	}

	// bool r = true;
	bool r = !F->isDeleted(); //  and  !F->isVariadic(); disabled, instead we force bindings with lambda for variadic

	if( F->isOverloadedOperator() ) {
		// outs() << "Operator: " << F->getNameAsString() << '\n';
		if( !isa<CXXMethodDecl>(F) or (cpp_python_operator(*F).size() == 0) ) return false;
	}

	r &= F->getTemplatedKind() != FunctionDecl::TK_FunctionTemplate /*and  !F->isOverloadedOperator()*/ and !isa<CXXConversionDecl>(F) and !F->isDeleted();

	QualType rt(F->getReturnType());

	r &= is_bindable(rt);

	for( auto p = F->param_begin(); p != F->param_end(); ++p ) r &= is_bindable((*p)->getOriginalType().getCanonicalType());
	// outs() << "is_bindable: " << F->getQualifiedNameAsString() << " " << r << "\n";

	if( r && is_banned_symbol(F) ) return false;
	return r;
}

/// check if generator can create binding
bool is_bindable(FunctionDecl const *F)
{
	static llvm::DenseMap<FunctionDecl const *, bool> cache;
	auto it = cache.find(F);
	if( it != cache.end() ) return it->second;
	else {
		bool r = is_bindable_raw(F);
		cache.insert({F, r});
		return r;
	}

	// static std::map<CXXRecordDecl const *, bool> cache;
	// auto it = cache.find(C);
	// if( it != cache.end() ) return it->second;
	// else {
	// 	bool r = is_bindable_raw(C);
	// 	cache.emplace(C, r);
	// 	return r;
	// }

	// static tsl::robin_map<FunctionDecl const *, bool> cache;
	// auto it = cache.find(F);
	// if( it != cache.end() ) return it->second;
	// else {
	// 	bool r = is_bindable_raw(F);
	// 	cache.insert( {F, r} );
	// 	return r;
	// }
}



/// check if methods could be overload in Python
bool is_overloadable(CXXMethodDecl const *M)
{
	// Pybind11 now allow returning a reference to primitive types or string so for now always return true
	return true;

	/*
	QualType qt = M->getReturnType().getCanonicalType();


	if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) {
		if( rt->getPointeeType()->isBuiltinType() ) return false;

		string r = standard_name( qt.getAsString() );
		static vector<string> const types_to_skip = {"std::string &", "const std::string &"};
		for(auto const &t : types_to_skip) if( r == t) return false;
	}

	return true;
	*/
}


bool FunctionBinder::bindable() const
{
	return binder::is_bindable(F);
}


/// check if user requested binding for the given declaration
void FunctionBinder::request_bindings_and_skipping(Config const &config, RequestFlags flags)
{
	if( (flags & RequestFlags::skipping) and is_skipping_requested(F, config) ) Binder::request_skipping();
	else if( (flags & RequestFlags::binding) and is_binding_requested(F, config) ) Binder::request_bindings();
}


/// extract include needed for this generator and add it to includes vector
void FunctionBinder::add_relevant_includes(IncludeSet &includes) const
{
	binder::add_relevant_includes(F, includes, 0);
}


/// generate binding code for this object and all its dependencies
void FunctionBinder::bind(Context &context)
{
	if( is_binded() ) return;

	string const module_variable_name = context.module_variable_name(namespace_from_named_decl(F));
	string const include = relevant_include(F);

	code() = "\t// " + F->getQualifiedNameAsString() + "(" + function_arguments(F) + ") file:" + (include.size() ? include.substr(1, include.size() - 2) : "") + " line:" + line_number(F) + "\n";
	code() += bind_function("\t" + module_variable_name, F, context);
	code() += "\n";
}

} // namespace binder
