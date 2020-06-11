#pragma once

namespace snow{
class BoostUse {
public:
    BoostUse(void) {};
    virtual ~BoostUse(void) {};

    void show_func_wrapper();
    void show_bind();

    //min_max 
    void show_minmax();
private:
    int _add(int a, int b);
};

} //end namespace snow 
