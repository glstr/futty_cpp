#pragma once

namespace snow{
class BoostUse {
public:
    BoostUse(void) {};
    virtual ~BoostUse(void) {};

    //function bind 
    void show_func_wrapper();
    void show_bind();

    void show_minmax();
    //smart ptr 
private:
    int _add(int a, int b);
};

} //end namespace snow 
