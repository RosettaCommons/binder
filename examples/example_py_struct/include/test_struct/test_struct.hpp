

#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include <string>
#include <vector>

namespace testers {
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

};

struct thingy {
	thingy(std::string const & x) { hello = x; }
	std::string hello;
};


thingy
get_thing(thingy & x ) {
	thingy new_thing(x);
	new_thing.hello += " xx";
	return new_thing;
}

}

#endif
