#include "std_facilities.h"
//双向链表
struct Link{//struct里的成员默认都是public
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v,Link* p=nullptr,Link* s=nullptr):
    value(v),prev(p),succ(s){}
};
//在p之前插入n,并返回n
// x><p   n
Link* insert(Link*p,Link*n){
    if(p==nullptr) return n;
    if(n==nullptr) return p;
    n->succ=p;
    n->prev=p->prev;
    if(n->prev) n->prev->succ=n;//如果p前面原本有node，就让该node->succ=n;
    p->prev=n;
    return n;
}
//在p后添加n 返回n
Link* add(Link*p,Link* n){
    if(p==nullptr) return n;
    if(n==nullptr) return p;
    n->prev=p;
    n->succ=p->succ;
    if(p->succ){
        p->succ->prev=n;
    }
    p->succ=n;
    return n;
}
//清除p返回后继
Link* erase(Link* p){
    if(p==nullptr) return nullptr;
    Link* x1=p->prev;
    Link* x2=p->succ;
    if(x1==x2&&x1==nullptr){
        
    }else if(x1&&x2){
        x1->succ=x2;
        x2->prev=x1;
       
        
    }else if(x1&&x2==nullptr){
        x1->succ=nullptr;
        
       
    }else if(x1==nullptr&&x2){
        x2->prev=nullptr;
    }
    p->prev=nullptr;
    p->succ=nullptr;
    return x2;
}
//从p开始找值，未找到则nullptr
Link* find(Link*p,const string& tar){
    while(p){
        if(p->value==tar) break;
        p=p->succ;
    } 
    return p;
}
//从p开始往前移动n个，未找到则nullptr
Link* advance(Link* p,int n){
    if(n<0){
        n=(-1)*n;
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
void print(Link* h){
    while(h){
        cout<<h->value<<' ';
        h=h->succ;
    }
    cout<<'\n';
}
int main(){
    Link* p=new Link("Thor");
    p=insert(p,new Link("Odin"));
    p=insert(p,new Link("Zeus"));
    p=insert(p,new Link("Freia"));
    Link* p1=new Link("Hera");
    p1=insert(p1,new Link("Athena"));
    p1=insert(p1,new Link("Mars"));
    p1=insert(p1,new Link("Poseidon"));
    print(p);
    print(p1);
    Link* temp=find(p1,"Mars");
    if(temp) temp->value="Ares";
    print(p1);
    Link* temp1=find(p,"Zeus");
    if(temp1){
        if(temp1==p) p==temp1->succ;
        erase(temp1);
        p1=insert(p1,temp1);
    }
    print(p);
    print(p1);
}