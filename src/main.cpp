#include "howuse.cpp"
#include "pointer_use.h"
#include <stdlib.h>

int main(){
    HowUser* h = new HowUser;
    //h->showUsageOfProto();
    //h->showUsageRapidjson();
    //h->showSize();
    //h->showStringLength();
    h->stringOperation();
    int a = *h;
    HowUser l;
    l = l + *h;
    int b = l;
    cout << a << endl;
    cout << b << endl;
    delete h;
    h = NULL;
}



