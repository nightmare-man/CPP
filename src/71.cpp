#include "std_facilities.h"
constexpr int xxx(int x){
    int sum=1;
    for(int i=x;i>=1;i--){
        sum*=i;
    }   
    return sum;
}
vector<int> gv{1,2,4,8,16,32,64,128,256,512};
void print_v(const vector<int>& v){
    for(int x:v){
        cout<<x<<' ';
    }
    cout<<'\n';
}
void f(vector<int>& v){
    vector<int> lv(10);
    lv=gv;
    print_v(lv);
    vector<int> lv2{v};
    print_v(lv2);
}
int main(){
    f(gv);
    vector<int> vv{xxx(1),xxx(2),xxx(3),xxx(4),xxx(5),xxx(6),xxx(7),xxx(8),xxx(9),xxx(10)};
    f(vv);
}