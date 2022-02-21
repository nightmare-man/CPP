#pragma once
#include <algorithm>
#include <iostream>
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
        T& operator[](int n);
        //不太可能调用这个函数啊，既然是const 那怎么初始化的呢？
        //怎么push_back赋值的；
        //新解释，该函数是例如const Mvector<int>时会被调用
        //不存在Mvector<const int> 因为这样无法初始化
        const T& operator[](int n)const;
    private:
        int sz;
        int space;
        T* elem;
};
template<class T> T& Mvector<T>::operator[](int n){
    std::cout<<"normal call"<<'\n';
    return elem[n];
}
template<class T> const T& Mvector<T>::operator[](int n)const{
    std::cout<<"const call"<<'\n';
    return elem[n];
}
