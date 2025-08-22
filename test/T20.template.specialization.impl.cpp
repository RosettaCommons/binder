#include "T20.template.specialization.hpp"
#include <iostream>

template<typename T>
void SampleNamespace::PairClass<T>::printHello()
{
	std::cout << "Hello" << std::endl;
}
