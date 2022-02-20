#include "std_facilities.h"
class Mvector{
    public:
        Mvector():sz{0},space{0},elem{nullptr}{}
        Mvector(int z):sz{sz},space{sz},elem{new double[sz]}{
            for(int i=0;i<sz;i++){
                elem[i]=0;
            }
        }
        ~Mvector(){delete[] elem;}
        Mvector(Mvector& v):sz{v.sz},space{v.space}{
            elem=new double[sz];
            for(int i=0;i<sz;i++){
                elem[i]=v.elem[i];
            }
        }
        Mvector& operator=(Mvector& v){
            if(&v==this) return *this;
            if(space>=v.sz){
                sz=v.sz;
                for(int i=0;i<v.sz;i++){
                    elem[i]=v.elem[i];
                }
            }else{
                double* newalloc=new double[v.sz];
                for(int i=0;i<v.sz;i++){
                    newalloc[i]=v.elem[i];
                }
                delete[] elem;
                elem=newalloc;
                sz=v.sz;
                space=sz;
            }
            return *this;
        }
        Mvector(Mvector&& v):sz{v.sz},space{v.space},elem{v.elem}{
		    v.elem=nullptr;
            v.sz=0;
            v.space=0;
        }
        //什么时候用移动构造，编译器觉得右边不会再被使用的时候就用
        Mvector& operator=(Mvector&& v){//右值引用 移动构造
            delete[] elem;
            elem=v.elem;
            v.elem=nullptr;
            sz=v.sz;
            space=v.space;
            return *this;
        }
        double& operator[](int n){return elem[n];}
        double operator[](int n)const{return elem[n];}
        int size()const{return sz;}
        int capacity()const{return space;}
        void resize(int newsize){
		    reserve(newsize);
            for(int i=0;i<newsize;i++)elem[i]=0;
            sz=newsize;
        }
        void push_back(double d){
            if(space==0) reserve(8);
            else if(sz==space) reserve(2*space);
            elem[sz]=d;
            sz++;
        }
        void reserve(int newalloc){
            if(newalloc<=space)return;
            double* p=new double[newalloc];
            for(int i=0;i<sz;i++)p[i]=elem[i];
            delete[] elem;
            elem=p;
            space=newalloc; 
        }
    private:
        int sz;
        double* elem;
        int space;
};
int main()
{

	cout<<"nihao";
	Mvector a;
	a.push_back(10);
	cout<<a[0]<<'\n';
	cout<<a.size()<<'\n';
	cout<<a.capacity()<<'\n';
}
