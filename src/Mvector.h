#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;
template<class T,class A=allocator<T>>
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
        //实际上这里使用new是不满足要求的，因为我们只想分配内存
        //而没有想对分配的内存初始化，而这正是new的缺点
        /*void reserve(int newsize){
            if(newsize<=space) return;
            T* p=new T[newsize];
            std::copy(elem,elem+sz,p);
            delete[] elem;
            elem=p;
            space=newsize;
        }*/
        void reserve(int newsize);
        //往末尾添加一个元素
        /*
        void push_back(T t){
            if(space==0) reserve(8);
            else if(sz==space) reserve(2*space);
            elem[sz]=t;
            sz++;
        }*/
        //resize分配并默认初始化
        /*void resize(int newsize){
            reserve(newsize);
            for(int i=0;i<sz;i++) elem[i]=T();
            sz=newsize;
        }*/
        //重新改编vector的大小，给其初始化，多余的部分变回未初始化
        void resize(int newsize,T t=T());
        //push_back 如果空间不够，调用reserve重新分配
        //然后将val赋值给新空间，使用const T& 免得不断传值复制
        void push_back(const T& val);
        T& operator[](int n);
        //不太可能调用这个函数啊，既然是const 那怎么初始化的呢？
        //怎么push_back赋值的；
        //新解释，该函数是例如const Mvector<int>时会被调用
        //不存在Mvector<const int> 因为这样无法初始化
        const T& operator[](int n)const;
        T& at(int n);
        const T& at(int n)const;
    private:
        int sz;
        int space;
        T* elem;
        A alloc;
};
template<class T,class A> T& Mvector<T,A>::at(int n){
    if(n<0||n>=sz) throw std::out_of_range();
    return elem[n];
}
template<class T,class A> const T& Mvector<T,A>::at(int n)const{
    if(n<0||n>=sz) throw std::out_of_range();
    return elem[n];
}
template<class T,class A> void Mvector<T,A>::reserve(int newsize){
    if(newsize<=space) return;
    //分配原始空间
    T* newalloc=alloc.allocate(newsize);
    //对每一个进行拷贝初始化
    for(int i=0;i<sz;i++) alloc.construct(&newalloc[i],elem[i]);
    //将初始化变回未初始化空间
    for(int i=0;i<sz;i++) alloc.destroy(&elem[i]);
    //回收原空间
    alloc.deallocate(elem,space);
    elem=newalloc;
    space=newsize;
} 
//默认值只放在声明就行了，不能放在定义
template<class T,class A> void Mvector<T,A>::resize(int newsize,T t){
    reserve(newsize);
    for(int i=0;i<newsize;i++) alloc.construct(&elem[i],t);
    for(int i=newsize;i<space;i++) alloc.destroy(&elem[i]);
    sz=newsize;
} 
template<class T,class A> void Mvector<T,A>::push_back(const T& val){
    if(space==0) reserve(8);
    else if(sz==space) reserve(2*space);
    alloc.construct(&elem[sz],val);
    sz++;
}
template<class T,class A> T& Mvector<T,A>::operator[](int n){
    std::cout<<"normal call"<<'\n';
    return elem[n];
}
template<class T,class A> const T& Mvector<T,A>::operator[](int n)const{
    std::cout<<"const call"<<'\n';
    return elem[n];
}
