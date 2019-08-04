
#include "boost_use.h"

#include <iostream>

#include <boost/bind.hpp>
#include <boost/function.hpp>

using namespace std;

namespace snow{
void BoostUse::show_func_wrapper() {
    boost::function<int (BoostUse*, int, int)> f = &BoostUse::_add;
    int res = f(this, 2, 3);
    cout << "res:" << res << endl;
}

void BoostUse::show_bind() {
    boost::function<int (BoostUse*, int, int)> f = &BoostUse::_add;
    auto g = boost::bind(f, this, _1, 2); 
    int res = g(19);
    cout << "res:" << res << endl;
}

void BoostUse::show_shared_ptr() {
    
}

int BoostUse::_add(int a, int b) {
    return a + b;
}

} //end namespace snow
