
#include "boost_use.h"

#include <iostream>
#include <list>

#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>

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

void BoostUse::show_minmax() {
    std::list<float> buffer_data = {0.1, 1.1, 2.3, 4.5, 7.9, 8.5};       
    typedef list<float>::const_iterator iterator;
    std::pair<iterator, iterator> result2 =
        boost::minmax_element(buffer_data.begin(), buffer_data.end());
    cout << "the min:" << *(result2.first) << ","
        << "the max:" << *(result2.second);
}

} //end namespace snow
