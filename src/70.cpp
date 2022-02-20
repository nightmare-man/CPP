#include "std_facilities.h"
constexpr int xxx(int x){
    int sum=1;
    for(int i=x;i>=1;i--){
        sum*=i;
    }   
    return sum;
}
int ga[10]={1,2,4,8,16,32,64,128,256,512};
void f1(int b[],int sz){
    int la[10];
    copy(ga,ga+10,la);
    for(int i=0;i<10;i++){
        cout<<la[i]<<' ';
    }
    cout<<"la end\n";
    int* p=new int[sz];
    copy(b,b+sz,p);
    for(int i=0;i<sz;i++){
        cout<<p[i]<<' ';
    }
    cout<<"p end\n";
    delete[] p;
}
int main(){
    f1(ga,10);
    int aa[10]={xxx(1),xxx(2),xxx(3),xxx(4),xxx(5),xxx(6),xxx(7),xxx(8),xxx(9),xxx(10)};
    f1(aa,10);
    return 0;
}