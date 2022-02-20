#include "std_facilities.h"
int global=10;
int* f(){
    int local3=10;
    return &local3;
}
int main(){
    int local1=10;
    int local2=10;
    int* p=new int(10);
    int* g=&global;
    int* l1=&local1;
    int* l2=&local2;
    int* l3=f();
    cout<<"堆比静态储存区的地址"<<(p>g?"大":"小")<<'\n';
    cout<<"堆比栈的地址"<<(p>l1?"大":"小")<<'\n';
    cout<<"静态储存区比栈"<<(g>l1?"大":"小")<<'\n';    
    cout<<"栈是向"<<(l1>l3?"下":"上")<<"增长\n"; 
    return 0;   
}