// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/binder.hpp
/// @brief  Classes IncludeSet and Binder
/// @author Sergey Lyskov

#ifndef _INCLUDED_binder_hpp_
#define _INCLUDED_binder_hpp_

#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>

#include <llvm/Support/raw_ostream.h>
#include <llvm/ADT/DenseMap.h>
//#include <tsl/robin_map.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace binder {

class Config;
class Context;

// structure to hold include set information and set of NamedDecl objects that was already queried for includes
class IncludeSet
{

public:
	// add include to the set
	void add_include(std::string const &i) { includes_.push_back(i); }

	// check if declaration is already in stack with level at lease as 'level' or lower and add it if it is not - return true if declaration was added
	bool add_decl(clang::NamedDecl const *, int level);

	std::vector<std::string> const &includes() const { return includes_; }

	// remove all includes and clear up the stack
	void clear();

private:
	std::vector<std::string> includes_;

	//using StackType = std::unordered_map<clang::NamedDecl const *, int>;
	using StackType = llvm::DenseMap<clang::NamedDecl const *, int>;
	//using StackType = tsl::robin_map<clang::NamedDecl const *, int>;

	StackType stack_;

	friend void add_relevant_includes_cached(clang::CXXRecordDecl const *C, IncludeSet &includes);
};


enum RequestFlags : int8_t {
	none=0, skipping = 1, binding = 2,
};
inline RequestFlags operator|(RequestFlags a, RequestFlags b) { return static_cast<RequestFlags>(static_cast<int>(a) | static_cast<int>(b)); }
inline RequestFlags operator&(RequestFlags a, RequestFlags b) { return static_cast<RequestFlags>(static_cast<int>(a) & static_cast<int>(b)); }

/// Bindings Generator - represent object that can generate binding info for function, class, enum or data variable
class Binder
{
public:
	typedef std::string string;

	virtual ~Binder() {}

	/// Generate string id that uniquely identify C++ binding object. For functions this is function prototype and for classes forward declaration.
	virtual string id() const = 0;

	// return Clang AST NamedDecl pointer to original declaration used to create this Binder
	virtual clang::NamedDecl const *named_decl() const = 0;

	/// check if generator can create binding
	virtual bool bindable() const = 0;

	bool binding_requested() const { return binding_requested_; };
	bool skipping_requested() const { return skipping_requested_; };

	/// request bindings for this generator
	void request_bindings() { binding_requested_ = true; }

	/// request skipping for this generator
	void request_skipping() { skipping_requested_ = true; }


	/// check if user supplied config requested binding for the given declaration and if so request it
	virtual void request_bindings_and_skipping(Config const &, RequestFlags flags = RequestFlags::skipping | RequestFlags::binding)  = 0;

	/// extract include needed for this generator and add it to includes vector
	virtual void add_relevant_includes(IncludeSet &) const = 0;

	/// generate binding code for this object and all its dependencies
	virtual void bind(Context &) = 0;

	/// return true if code was already generated for this object
	bool is_binded() const;

	/// return binding code
	string &code() { return code_; }
	string const &code() const { return code_; }

	/// return true if object is declared in system header
	bool is_in_system_header();

	/// return vector of declarations that need to be binded before this one could
	virtual std::vector<clang::CXXRecordDecl const *> dependencies() const { return std::vector<clang::CXXRecordDecl const *>(); }

	/// return prefix portion of bindings code
	virtual string prefix_code() const { return string(); }

	/// return unique strting ID for this binder
	explicit operator std::string() const { return id(); /*named_decl()->getQualifiedNameAsString();*/ }

private:
	bool binding_requested_ = false, skipping_requested_ = false;

	string code_;
};

typedef std::shared_ptr<Binder> BinderOP;

typedef std::vector<BinderOP> Binders;

llvm::raw_ostream &operator<<(llvm::raw_ostream &os, Binder const &b);

} // namespace binder

#endif // _INCLUDED_binder_hpp_
