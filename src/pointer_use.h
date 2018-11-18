#pragma once
#include <stdio.h>

class PointerUse{
public:
    PointerUse(void);
    virtual ~PointerUse(void);

    void showPointerUse();
private:
    int _num;
};
