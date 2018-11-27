#include "howuse.cpp"
#include "pointer_use.h"
#include <stdlib.h>

int main(){
    HowUser* h = new HowUser;
    //h->showUsageOfProto();
    //h->showUsageRapidjson();
    //h->showSize();
    //h->showStringLength();
    h->showAsm();
    delete h;
    h = NULL;
}



