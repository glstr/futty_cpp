#include "pointer_use.h"
#include <stdlib.h>

int main(){
    PointerUse *p = new PointerUse();
    p->showPointerUse();
    delete p;
    p->showPointerUse();
}



