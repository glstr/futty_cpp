
#include "utils.h"

#include <iostream>

int t_add(int a, int b) {
    return a + b;
}

void t_add_more() {
    add_func a = t_add;
    std::cout << a(1, 3) << std::endl;
}

void StringHelper::Split(const std::string& input) {
    return;  
}
