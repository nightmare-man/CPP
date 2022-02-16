#include "link.h"
#include "iostream"
Link* Link::insert(Link* n){
    if(this==nullptr) return n;
    if(n==nullptr) return this;
    n->succ=this;
    n->prev=this->prev;
    if(this->prev) this->prev->succ=n;
    this->prev=n;
    return n;
}
Link* Link::add(Link* n){
    if(this==nullptr) return n;
    if(n==nullptr) return this;
    n->prev=this;
    n->succ=this->succ;
    if(this->succ) this->succ->prev=n;
    this->succ=n;
    return n;
}
Link* Link::erase(){
    if(this==nullptr) return this;
    Link* x1=this->prev;
    Link* x2=this->succ;
    if(x2==nullptr)x1->succ=nullptr;
    if(x1==nullptr)x2->prev=nullptr;
    this->prev=nullptr;
    this->succ=nullptr;
    return x2;
}
Link* Link::find(const string& v){
    Link* p=this;
    while(p){
        if(p->val==v)break;
        p=p->succ;
    }
    return p;
}
Link* Link::advance(int n){
    Link* p=this;
    if(n<0){
        n*=-1;
        while(n>0&&p){
            p=p->succ;
            n--;
        }
    }else if(n>0){
        while(n>0&&p){
            p=p->prev;
            n--;
        }
    }
    return p;
}
void Link::print(){
    Link* p=this;
    while(p){
        cout<<p->val<<' ';
        p=p->succ;
    }
    cout<<'\n';
}