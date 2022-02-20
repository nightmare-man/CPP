#pragma once
#include <algorithm>
template<typename T>
class Mvector{
    public:
        Mvector():sz{0},space{0},elem{nullptr}{}
        Mvector(int s):sz{s},space{s},elem{new T[s]}{
        }
        ~Mvector(){delete[] elem;}
        Mvector(Mvector& a):sz{a.sz},space{a.space},elem{new T[sz]}{
            std::copy(a.elem,a.elem+sz,elem);
        }
        Mvector& operator=(Mvector& a){
            if(&a==this) return *this;
            if(space<a.sz){
                T* p=new T[a.sz];
                std::copy(a.elem,a.elem+a.sz,p);
                sz=a.sz;
                space=a.sz;
                delete[] elem;
                elem=p;
                return *this;
            }else{
                std::copy(a.elem,a.elem+a.sz,elem);
                sz=a.sz;
                return *this;
            }
        }
        Mvector(Mvector&& a):sz{a.sz},space{a.space},elem{a.elem}{
            a.elem=nullptr;
        }
        Mvector& operator=(Mvector&& a){
            sz=a.sz;
            space=a.space;
            elem=a.elem;
            a.elem=nullptr;
            return *this;
        }
        int size()const{return sz;}
        int capacity()const{return space;}
        //分配更大空间，原来的元素保存
        void reserve(int newsize){
            if(newsize<=space) return;
            T* p=new T[newsize];
            std::copy(elem,elem+sz,p);
            delete[] elem;
            elem=p;
            space=newsize;
        }
        //往末尾添加一个元素
        void push_back(T t){
            if(space==0) reserve(8);
            else if(sz==space) reserve(2*space);
            elem[sz]=t;
            sz++;
        }
        //resize分配并默认初始化
        void resize(int newsize){
            reserve(newsize);
            for(int i=0;i<sz;i++) elem[i]=T();
            sz=newsize;
        }
        T& operator[](int n){
            return elem[n];            
        }
        const T& operator[](int n)const{
            return elem[n];
        }
    private:
        int sz;
        int space;
        T* elem;
};
