#pragma once
#include "string"
using namespace std;
class Link{
    public:
        string val;
        Link(string v,Link* p=nullptr,Link* s=nullptr):val{v},prev{p},succ{s}{}
        Link* insert(Link* n);
        Link* add(Link* n);
        Link* erase();
        Link* find(const string&v);
        Link* advance(int n);
        void print();
        Link* Prev()const{return prev;}
        Link* Succ()const{return succ;}
    private:
        Link* prev;
        Link* succ;
};