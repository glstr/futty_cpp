#pragma once

namespace snow{
class BoostUse {
public:
    BoostUse(void) {};
    virtual ~BoostUse(void) {};

    //function bind 
    void show_func_wrapper();
    void show_bind();

    //smart ptr 
private:
    int _add(int a, int b);
};

} //end namespace snow 
