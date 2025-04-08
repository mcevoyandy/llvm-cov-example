#include "cool_stuff.hpp"

#include <iostream>

namespace my_namespace {

CoolStuff::CoolStuff() {
    std::cout << "CoolStuff constructor" << std::endl;
}

CoolStuff::~CoolStuff() {
    std::cout << "CoolStuff destructor" << std::endl;
}

void CoolStuff::cool_function() {
    std::cout << "Cool function" << std::endl;
    cool_variable_ = 42;
}

int CoolStuff::another_cool_function() {
    std::cout << "Another cool function" << std::endl;
    return cool_variable_;
}

int CoolStuff::the_coolest_function(int a) {
    std::cout << "The coolest function" << std::endl;
    if (a % 2 == 0) {
        return 42;
    }


    return 33;
}

}
