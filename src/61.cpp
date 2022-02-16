#include "std_facilities.h"
void fun1(){
    int x=10;
    int*p=&x;
    *p=7;
    int x2=*p;
    int* p2=&x2;
    p2=p;
    p=&x2;
}
void fun2(){
    int y=10;
    int& r=y;
    r=7;
    int y2=r;
    int& r2=y2;
    r2=r;//这里将y的值赋给y2，不是改变引用
    cout<<r2<<'\n';
   // r=&y2;
}
int main(){
    fun2();
    return 0;
}