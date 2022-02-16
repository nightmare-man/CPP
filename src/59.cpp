#include "std_facilities.h"
void fun1(){
    int* pi=new int[100];
    char* x=reinterpret_cast<char*>(pi);
    cout<<sizeof(*pi)<<'\n';
}
void fun2(){
    int a=100;
    int* p=&a;

    cout<<p[-100]<<'\n';
    p[-100]=100;
    cout<<p[-100]<<'\n';
}
void fun3(){
    double * p0=nullptr;
    double * p1=new double;
    double * p2=new double{5.4};
    double * p3=new double[6]{1,2,3,4,5};
    //cout<<p0[0]<<'\n';
    if(p0==0) cout<<"nullptr is 0\n"; 
}
double* fun4(){
    double* p=new double[100];
    double* res=new double[200]{99,1,2};
    delete[] p;//清除p全部
    return res;
}
void fun5(){
    double* p=nullptr;
    delete[] p;
}
int main(){
    fun5();
    return 0;
}