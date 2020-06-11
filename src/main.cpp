#include "howuse.h"

#include <stdlib.h>
#include <iostream>

#include "basic_use.h"
#include "boost_use.h"
#include "pointer_use.h"

using namespace std;

int main() {
    //snow::HowUser* h = new snow::HowUser;
    //snow::BoostUse* b = new snow::BoostUse;
    //snow::BasicUser* bu = new snow::BasicUser;
    ////b->show_minmax();
    //h->rapidJsonHelperUsage();
    ////bu->struct_usage(); 
    //delete h;
    //delete b;
    //delete bu;
    
    struct ListNode {
        ListNode* pnext;
        int value;
    };

    ListNode head;
    head.value = 1; 
    ListNode ele1;
    ele1.value = 2;
    ListNode ele2;
    ele2.value = 3;

    head.pnext = &ele1;
    ele1.pnext = &ele2;
    ele2.pnext = NULL;

    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->value << endl;
        temp = temp->pnext;
    }
    return 0;
}

