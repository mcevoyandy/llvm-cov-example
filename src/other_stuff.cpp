#include "other_stuff.hpp"

#include <iostream>

namespace my_namespace {

OtherStuff::OtherStuff() {
    std::cout << "OtherStuff constructor" << std::endl;
}

OtherStuff::~OtherStuff() {
    std::cout << "OtherStuff destructor" << std::endl;
}

void OtherStuff::some_function() {
    std::cout << "Some function" << std::endl;
    a_variable_ = 42;
}

int OtherStuff::some_other_function() {
    std::cout << "Some other function" << std::endl;
    return a_variable_;
}

int OtherStuff::another_function(int a) {
    std::cout << "Another function" << std::endl;
    if ((a % 2 == 0 && a > 42) || (a % 2 == 1 && a < 42))
    {
        return 42;
    }

    return 33;
}

}
