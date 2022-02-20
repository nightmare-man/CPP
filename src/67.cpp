#include "std_facilities.h"
class X{
    public:
        //默认不是explicit，这样的话允许
        //隐式类型转换，造成很多问题
        //添加explicit阻止隐式类型转换
        explicit X(int x):p{x}{}
        void print(){
            cout<<p<<'\n';
        }
    private:
        int p;
};
int main(){
    X a=X{10};
    a.print();
}