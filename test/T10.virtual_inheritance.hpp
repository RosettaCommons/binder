// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

#pragma once

#include <string>
#include <vector>
#include <memory>

//
// example code is based on https://github.com/RosettaCommons/binder/issues/241
//

template <int I>
class Animal {
public:
    virtual ~Animal() = default;
    virtual void Eat() const = 0;
	bool isAnimal() { return true;}
    virtual bool isDog() const;
};

template <int I>
bool Animal<I>::isDog() const {
    return false;
}

template <int I>
class Mammal : public virtual Animal<I> {
public:
    virtual void Breathe() const = 0;
};

template <int I>
class Dog: public virtual Mammal<I> {
public:
    void Eat() const override { printf("Eat\n");}
    void Breathe() const override { printf("Breathe\n");}
    bool isDog() const override;
};

template <int I>
bool
Dog<I>::isDog() const {
    return true;
}

template <int I>
bool isThisAnimalADog(const std::shared_ptr<Animal<I>> &a) { return a->isDog();}

inline void initiate(Dog<1> p) {};
template bool isThisAnimalADog<1>(const std::shared_ptr<Animal<1>> &a);
