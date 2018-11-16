#include "pointer_use.h"

#include <iostream>
#include <sstream>
using namespace std;

PointerUse::PointerUse(void): _num(1){
}

PointerUse::~PointerUse(void){
    _num = 2;
}

void PointerUse::showPointerUse(){
    stringstream ss;
    ss << "hello world "<< 1 << endl;
    cout << ss.str();
    int n = 5;
    char* c = new char[n];
    for(int i = 0; i < n; i++){
        c[i] = 'i';
    }
    c[n] = 'e';
    char* d = c + 5;
    delete[] c;
    cout << d << endl;
    d--;
    cout << d << endl;
    cout << c << endl;
    c[0] = 'l';
    void* e = (void*)c;
    cout << e << endl;
    cout << _num << endl;
}


