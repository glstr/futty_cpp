#include "howuse.h"
#include "pointer_use.h"
#include <stdlib.h>

int main(){
    snow::HowUser* h = new snow::HowUser;
    //h->show_typedef();
    h->namespace_test()
    delete h;
   }



