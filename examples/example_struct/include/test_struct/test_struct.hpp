

#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include <string>
#include <vector>
#include <iostream>

namespace testers {


namespace {
	void
	print_an_int( int const & myint ) {
		std::cout << "myint is: " << myint << std::endl;
	}
}


struct test_my_struct {
	int an_int;
	std::string a_string;
	std::vector<int> a_vector;
	float a_float;

	test_my_struct() {
		an_int = 27;
		a_string = "TEST_STRING";
		a_vector = std::vector<int>{1,2,3,4,5};
		a_float = 88.88;
	}

	void
	increment_int() {
		++an_int;
	}

	void
	add_float() {
		a_float += 22.22;
	}

	void
	append_vec() {
		a_vector.push_back(a_vector.back()+1);
	}

	void
	p_int() {
		print_an_int(an_int);
	}

};
}

#endif
