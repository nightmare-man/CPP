#include "std_facilities.h"
class X{
    public:
        X():sz{0},val{nullptr}{}
        X(int len):sz{len},val{new int[len]}{}
        ~X(){delete[] val;}
        int& operator[](int n){
            return val[n];
        }
        int operator[](int n)const{
            return val[n];//对const X& 进行重载
        }
        void print(){
            for(int i=0;i<sz;i++){
                cout<<val[i]<<' ';
            }
            cout<<'\n';
        }
    private:
        int sz;
        int* val;
};
int main(){
    const X a{10};
    cout<<a[1]<<'\n';
    
}