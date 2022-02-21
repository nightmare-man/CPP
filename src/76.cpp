#include "Mvector.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void func(Mvector<string>& v){
    sort(&v[0],&v[v.size()]);
}
int main(){
    Mvector<int> p(10);
    const Mvector<int> p11(20);
    cout<<p11[0]<<'\n';
    return 0;
}