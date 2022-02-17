#include "std_facilities.h"
class MyS{
    public:
        MyS():val{new double{-1}}{
            cout<<"执行了MyS的默认初始化\n";
        }
        MyS(double v):val{new double{v}}{
            cout<<"执行了MyS的初始化，malloc了double,值为"<<v<<'\n';
        }
        ~MyS(){cout<<"将执行了MyS的析构，delete："<<val<<'\n';delete val;}
        double Val()const{return *val;}
        double* print_val_p()const{return val;}
    private:
        double* val;
};
class MyV{
    public:
        MyV(const MyV& p):val{new MyS{}}{
            *val=*(p.print_val_p());
            cout<<"MyV执行了val指向的MyS复制\n";
        }
        MyV():val{new MyS{-1}}{
            cout<<"执行了MyV的初始化，malloc了MyS,默认初始化\n";
        }
        MyV(double x):val{new MyS{x}}{
            cout<<"执行了MyV的初始化，malloc了MyS,传入"<<x<<'\n';
        }
        ~MyV(){cout<<"将执行了MyV的析构，delete："<<val<<'\n';delete val;}
        double Val()const{return val->Val();}
        MyS* print_val_p()const{return val;}
    private:
        MyS* val;
};
int main(){
    MyV p{10};
    MyV p1=p;
    cout<<"p的val指针为"<<p.print_val_p();
    cout<<"p的值为:"<<p.Val()<<'\n';
    cout<<"p1的val指针为"<<p1.print_val_p();
    cout<<"p1的值为:"<<p1.Val()<<'\n';
    return 0;
}