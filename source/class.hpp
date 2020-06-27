// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/class.hpp
/// @brief  Binding generation for C++ struct and class objects
/// @author Sergey Lyskov

#ifndef _INCLUDED_class_hpp_
#define _INCLUDED_class_hpp_

#include <context.hpp>

#include <clang/AST/DeclCXX.h>

#if  (LLVM_VERSION_MAJOR >= 10)
#include <clang/AST/Attr.h>
#endif
#include <string>
#include <vector>
#include <set>

namespace binder {

// generate classtemplate specialization for ClassTemplateSpecializationDecl or empty string otherwise
std::string template_specialization(clang::CXXRecordDecl const *C);


// generate class name that could be used in bindings code indcluding template specialization if any
std::string class_name(clang::CXXRecordDecl const *C);


// generate qualified class name that could be used in bindings code indcluding template specialization if any
std::string class_qualified_name(clang::CXXRecordDecl const *C);


// generate vector<QualType> with all types that class uses if it tempalated
std::vector<clang::QualType> get_type_dependencies(clang::CXXRecordDecl const *C /*, bool include_members=false*/);


// generate vector<NamedDecl const *> with all declarations related to class
std::vector<clang::NamedDecl const *> get_decl_dependencies(clang::CXXRecordDecl const *C);


/// check if generator can create binding
bool is_bindable(clang::CXXRecordDecl const *C);

/// check if user requested binding for the given declaration
bool is_binding_requested(clang::CXXRecordDecl const *C, Config const &config);


/// check if user requested skipping for the given declaration
bool is_skipping_requested(clang::CXXRecordDecl const *C, Config const &config);


// extract include needed for declaration and add it to includes
void add_relevant_includes(clang::CXXRecordDecl const *C, IncludeSet &includes, int level);


/// Create forward-binding for given class which consist of only class type without any member, function or constructors
std::string bind_forward_declaration(clang::CXXRecordDecl const *C, Context &);


class ClassBinder : public Binder
{
public:
	ClassBinder(clang::CXXRecordDecl *c) : C(c) {}

	/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
	string id() const override;

	// return Clang AST NamedDecl pointer to original declaration used to create this Binder
	clang::NamedDecl * named_decl() const override { return C; };

	/// check if generator can create binding
    bool bindable() const override;

	/// check if user requested binding for the given declaration
	virtual void request_bindings_and_skipping(Config const &) override;

	/// extract include needed for this generator and add it to includes vector
	void add_relevant_includes(IncludeSet &includes) const override;

	/// generate binding code for this object by using external user-provided binder
	void bind_with(string const &binder, Context &);

	/// generate binding code for this object and all its dependencies
	void bind(Context &) override;

	std::vector<clang::CXXRecordDecl const *> dependencies() const override { return dependencies_; }

	/// return prefix portion of bindings code
	string prefix_code() const override { return prefix_code_; }

private:
	clang::CXXRecordDecl *C;

	std::string prefix_code_;
	std::vector<clang::FunctionDecl const *> prefix_includes;

	// vector of classes in which current class depend to be binded (usually base classes)
	std::vector<clang::CXXRecordDecl const *> dependencies_;

	/// check if any of the base classes is wrappable and if generate a string describing them: , pybind11::base<BaseClass>()
	std::string maybe_base_classes(Context &context);

	void generate_prefix_code();

	// generating bindings for public nested classes
	string bind_nested_classes(clang::CXXRecordDecl const *EC, Context &context);

	/// generate (if any) bindings for Python __str__ by using appropriate global operator<<
	std::string bind_repr(Context &);
};


} // namespace binder

#endif // _INCLUDED_class_hpp_
