// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/binder.cpp
/// @brief  Classes IncludeSet and Binder
/// @author Sergey Lyskov

#include <binder.hpp>

#include <type.hpp> // is_python_builtin

#include <clang/AST/ASTContext.h>

using std::string;
using std::vector;

namespace binder {

// const std::string _module_variable_name_{"M"};

// check if declaration is already in stack with level at least as 'level' or lower and add it if it is not - return true if declaration was added

bool IncludeSet::add_decl(clang::NamedDecl const *D, int level)
{
	auto it_inserted = stack_.insert( {D, level} );
	auto & it = it_inserted.first;
	auto & inserted = it_inserted.second;
	if(inserted) return true;
	else {
		if( it->second <= level ) return false;
		else {
			it->second = level;
			//it.value() = level;
			return true;
		}
	}

	// {
	// 	std::unordered_map<int, int> mp;
	// 	//tsl::robin_map<int, int> mp;
	// 	mp[0] = 0;
	// 	mp.find(0)->second = 1;
	// 	mp.insert({0, 1}).first->second = 2;
	// }


	// StackType::iterator it;
	// bool inserted;
	// std::tie(it, inserted) = stack_.insert( StackType::value_type(D, level) );


	// auto it = stack_.find(D);
	// if( it == stack_.end() ) {
	// 	 stack_[D] = level;
	// 	 return true;
	// }
	// else {
	// 	if( it->second <= level ) return false;
	// 	else {
	// 		it->second = level;
	// 		return true;
	// 	}
	// }

	// auto &l = stack_[D];
	// if( l.value and l.value <= level.value ) return false;
	// l = level;
	// return true;

	// if( stack_.count(D) and stack_[D] <= level ) return false;
	// stack_[D] = level;
	// return true;
}

// remove all includes and clear up the stack
void IncludeSet::clear()
{
	includes_.clear();
	stack_.clear();
}

/// return true if object declared in system header
bool Binder::is_in_system_header()
{
	using namespace clang;
	NamedDecl const *decl(named_decl());
	ASTContext &ast_context(decl->getASTContext());
	SourceManager &sm(ast_context.getSourceManager());

	return FullSourceLoc(decl->getLocation(), sm).isInSystemHeader();
}

// return true if code was already generate for this object
bool Binder::is_binded() const
{
	return code().size() or is_python_builtin(named_decl());
}

llvm::raw_ostream &operator<<(llvm::raw_ostream &os, Binder const &b)
{
	clang::NamedDecl const *decl = b.named_decl();

	string name = decl->getNameAsString();
	string qualified_name = decl->getQualifiedNameAsString();
	string path = decl->getQualifiedNameAsString().substr(0, qualified_name.size() - name.size());

	return os << "B{name=" << name << ", path=" << path << "\n"; //<< ", include= " code=\n" << b("module") << "\n}
}

} // namespace binder
