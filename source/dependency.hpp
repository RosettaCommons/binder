// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file  binder/dependency.hpp
/// @brief Dependency: A Binder class for dependency management

#ifndef _INCLUDED_dependency_hpp_
#define _INCLUDED_dependency_hpp_

#include <class.hpp>
#include <context.hpp>

namespace binder {

/// Dependency Binder class - helps managing dependencies between type bindings
/// The Dependency class indicates that the binding for a type is provided by
/// the binding of another class (the dependency).
/// (Prime example being an inner class whose binding is provided by its enclosing class)
/// The Dependency class does not generate any binding code!
class Dependency : public Binder {
  public:
	Dependency( clang::CXXRecordDecl const *c, clang::CXXRecordDecl const *dependency ) : C( c ) {
		dependencies_.push_back( dependency );
	};

	/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
	string id() const override {
		return class_qualified_name( C );
	};

	// return Clang AST NamedDecl pointer to original declaration used to create this Binder
	clang::NamedDecl const *named_decl() const override { return C; };

	bool bindable() const override { return false; }; // dependencies are not bindable

	virtual void request_bindings_and_skipping( Config const &config ) override{}; // nothing to do

	void add_relevant_includes( IncludeSet &includes ) const override{}; // nothing to do

	void bind( Context & ) override{}; // nothing to do

	std::vector<clang::CXXRecordDecl const *> dependencies() const override { return dependencies_; };

  private:
	clang::CXXRecordDecl const *C;

	// vector of classes in which current class depend to be binded (usually base classes)
	std::vector<clang::CXXRecordDecl const *> dependencies_;
};

} // namespace binder

#endif