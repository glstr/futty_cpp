#include "howuse.h"

#include <stdlib.h>

#include "boost_use.h"
#include "pointer_use.h"

int main(){
    snow::HowUser* h = new snow::HowUser;
    snow::BoostUse* b = new snow::BoostUse;
    h->show_queue();
    //h->show_map();
    //h->show_wg();
    //b->show_func_wrapper();
    //b->show_bind();
    delete h;
    delete b;
   }



