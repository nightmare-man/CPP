#include "link.h"
int main(){
    Link* h1=new Link("1");
    h1=h1->insert(new Link("3"));
    h1=h1->insert(new Link("4"));
    Link* temp=h1->find("4");
    temp->val="5";
    h1->print();
    temp->erase();
    h1->print();
    return 0;
}