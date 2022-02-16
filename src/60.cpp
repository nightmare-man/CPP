#include "std_facilities.h"
class My_vector{
    public:
        My_vector():sz{0},elem{nullptr}{}
        My_vector(int s):sz{s},elem{new double[s]}{
            for(int i=0;i<s;i++) elem[i]=0;
        }
        ~My_vector(){delete[] elem;cout<<"析构函数被调用了!\n";}
        int size()const{return sz;}
        double& operator[](int x){
            return elem[x];
        }
        void print()const;
    private:
        int sz;
        double* elem;
};
void My_vector::print()const{
    for(int i=0;i<sz;i++){
        cout<<elem[i]<<"\t";
    }
    cout<<'\n';
}
void ff(void* pv){
    void* pv2=pv;
    double* pd=static_cast<double*>(pv);
    int*pi=static_cast<int*>(pv);
    pd=reinterpret_cast<double*>(pi);
    int aa=100;
    const int* cp=&aa;//const在*左侧，表明修饰指针指向的变量是const
    int*const pc=&aa;//在指针变量左侧，表明指针变量不可变
    *pc=200;
}
int main(){
    
    return 0;
}
