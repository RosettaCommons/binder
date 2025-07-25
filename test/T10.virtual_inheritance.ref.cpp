// File: T10_virtual_inheritance.cpp
#include <T10.virtual_inheritance.hpp> // Animal
#include <T10.virtual_inheritance.hpp> // Dog
#include <T10.virtual_inheritance.hpp> // Mammal
#include <T10.virtual_inheritance.hpp> // initiate
#include <T10.virtual_inheritance.hpp> // isThisAnimalADog
#include <memory> // std::shared_ptr
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Animal file:T10.virtual_inheritance.hpp line:
struct PyCallBack_Animal_1_t : public Animal<1> {
	using Animal<1>::Animal;

	void Eat() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Animal<1> *>(this), "Eat");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Animal::Eat\"");
	}
	bool isDog() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Animal<1> *>(this), "isDog");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Animal::isDog();
	}
};

// Mammal file:T10.virtual_inheritance.hpp line:
struct PyCallBack_Mammal_1_t : public Mammal<1> {
	using Mammal<1>::Mammal;

	void Breathe() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Mammal<1> *>(this), "Breathe");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Mammal::Breathe\"");
	}
	void Eat() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Mammal<1> *>(this), "Eat");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Animal::Eat\"");
	}
	bool isDog() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Mammal<1> *>(this), "isDog");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Animal::isDog();
	}
};

// Dog file:T10.virtual_inheritance.hpp line:
struct PyCallBack_Dog_1_t : public Dog<1> {
	using Dog<1>::Dog;

	void Eat() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Dog<1> *>(this), "Eat");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Dog::Eat();
	}
	void Breathe() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Dog<1> *>(this), "Breathe");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Dog::Breathe();
	}
	bool isDog() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Dog<1> *>(this), "isDog");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Dog::isDog();
	}
};

void bind_T10_virtual_inheritance(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Animal file:T10.virtual_inheritance.hpp line:
		pybind11::class_<Animal<1>, std::shared_ptr<Animal<1>>, PyCallBack_Animal_1_t> cl(M(""), "Animal_1_t", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_Animal_1_t(); } ) );
		cl.def(pybind11::init<PyCallBack_Animal_1_t const &>());
		cl.def("Eat", (void (Animal<1>::*)() const) &Animal<1>::Eat, "C++: Animal<1>::Eat() const --> void");
		cl.def("isAnimal", (bool (Animal<1>::*)()) &Animal<1>::isAnimal, "C++: Animal<1>::isAnimal() --> bool");
		cl.def("isDog", (bool (Animal<1>::*)() const) &Animal<1>::isDog, "C++: Animal<1>::isDog() const --> bool");
		cl.def("assign", (class Animal<1> & (Animal<1>::*)(const class Animal<1> &)) &Animal<1>::operator=, "C++: Animal<1>::operator=(const class Animal<1> &) --> class Animal<1> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Mammal file:T10.virtual_inheritance.hpp line:
		pybind11::class_<Mammal<1>, std::shared_ptr<Mammal<1>>, PyCallBack_Mammal_1_t, Animal<1>> cl(M(""), "Mammal_1_t", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_Mammal_1_t(); } ) );
		cl.def(pybind11::init<PyCallBack_Mammal_1_t const &>());
		cl.def("Breathe", (void (Mammal<1>::*)() const) &Mammal<1>::Breathe, "C++: Mammal<1>::Breathe() const --> void");
		cl.def("assign", (class Mammal<1> & (Mammal<1>::*)(const class Mammal<1> &)) &Mammal<1>::operator=, "C++: Mammal<1>::operator=(const class Mammal<1> &) --> class Mammal<1> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // Dog file:T10.virtual_inheritance.hpp line:
		pybind11::class_<Dog<1>, std::shared_ptr<Dog<1>>, PyCallBack_Dog_1_t, Mammal<1>> cl(M(""), "Dog_1_t", "");
		cl.def( pybind11::init( [](){ return new Dog<1>(); }, [](){ return new PyCallBack_Dog_1_t(); } ) );
		cl.def( pybind11::init( [](PyCallBack_Dog_1_t const &o){ return new PyCallBack_Dog_1_t(o); } ) );
		cl.def( pybind11::init( [](Dog<1> const &o){ return new Dog<1>(o); } ) );
		cl.def("Eat", (void (Dog<1>::*)() const) &Dog<1>::Eat, "C++: Dog<1>::Eat() const --> void");
		cl.def("Breathe", (void (Dog<1>::*)() const) &Dog<1>::Breathe, "C++: Dog<1>::Breathe() const --> void");
		cl.def("isDog", (bool (Dog<1>::*)() const) &Dog<1>::isDog, "C++: Dog<1>::isDog() const --> bool");
		cl.def("assign", (class Dog<1> & (Dog<1>::*)(const class Dog<1> &)) &Dog<1>::operator=, "C++: Dog<1>::operator=(const class Dog<1> &) --> class Dog<1> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// isThisAnimalADog(const class std::shared_ptr<class Animal<1> > &) file:T10.virtual_inheritance.hpp line:
	M("").def("isThisAnimalADog", (bool (*)(const class std::shared_ptr<class Animal<1> > &)) &isThisAnimalADog<1>, "C++: isThisAnimalADog(const class std::shared_ptr<class Animal<1> > &) --> bool", pybind11::arg("a"));

	// initiate(class Dog<1>) file:T10.virtual_inheritance.hpp line:
	M("").def("initiate", (void (*)(class Dog<1>)) &initiate, "C++: initiate(class Dog<1>) --> void", pybind11::arg("p"));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T10_virtual_inheritance(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T10_virtual_inheritance, root_module) {
	root_module.doc() = "T10_virtual_inheritance module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T10_virtual_inheritance(M);

}

// Source list file: TEST/T10_virtual_inheritance.sources
// T10_virtual_inheritance.cpp
// T10_virtual_inheritance.cpp

// Modules list file: TEST/T10_virtual_inheritance.modules
// 
