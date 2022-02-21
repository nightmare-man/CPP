#include <iostream>
using namespace std;
template<class T,int N> struct Marray{
    Marray<T,N>(){
        for(int i=0;i<N;i++){
            elem[i]=T();
        }
    }
    T elem[N];
    T& operator[](int n);
    const T& operator[](int n)const;
    T* data(){return elem;}
    const T* data()const{return elem;}
    int size()const{return N;}
};
template<class T,int N> T& Marray<T,N>::operator[](int n){
    return elem[n];
}
template<class T,int N> const T& Marray<T,N>::operator[](int n)const{
    return elem[n];
}
int main(){
    Marray<string,15> a;
    a[0]="nihao";
    for(int i=0;i<15;i++){
        cout<<a[i]<<'\n';
    }
}