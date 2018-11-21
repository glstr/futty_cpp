#include "howuse.cpp"
#include "pointer_use.h"
#include <stdlib.h>

int main(){
    HowUser* h = new HowUser;
    //h->showUsageOfProto();
    //h->showUsageRapidjson();
    h->showSize();
    delete h;
    h = NULL;
}



