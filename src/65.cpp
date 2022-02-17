#include "std_facilities.h"
class MyS{
    public:
        MyS(double v):val{new double{v}}{
            cout<<"MyS参数初始化，参数为"<<v<<'\n';
        }
        MyS():val{new double}{
            cout<<"MyS默认初始化\n";
        }
        ~MyS(){
            cout<<"MyS将析构，val为"<<val<<'\n';
            delete val;}
        //拷贝构造
        MyS(const MyS& p):val{new double}{
            cout<<"MyS拷贝构造\n";
            *val=*(p.val);//成员函数里能访问private
        }
        //拷贝赋值
        MyS& operator=(const MyS& p){
            cout<<"MyS拷贝赋值\n";
            *val=*(p.val);//拷贝赋值，如果val是一个数组的指针的话，这里可能需要重新分配和p等大的空间
            //但是我们这里不是，只是个double的指针，因此没必要重新分配空间
            return *this;
        }
        //移动构造
        MyS(MyS&& p)noexcept:val{p.val}{
            cout<<"MyS移动构造\n";
            p.val=nullptr;
        }
        //移动赋值
        MyS& operator=(MyS&& p)noexcept{
            cout<<"MyS移动赋值\n";
            val=p.val;
            p.val=0;
            return *this;
        }
        double print(){return *val;}
    private:
        double* val;
};
MyS fun(){
    MyS s{10};
    return s;
}
int main(){
    MyS p=fun();//这里执行了两次移动构造，一次由
    //返回的s构造temp，一次由temp移动构造p
    //如果开启优化（默认开启的），直接一次构造得到p
    cout<<"p的val指向的double的值为"<<p.print()<<'\n';
    return 0;
}