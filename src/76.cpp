#include "Mvector.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;

int main(){
    Mvector<int> p(10);
    cout<<p[0]<<'\n';
    vector<int> p1(10);
    cout<<p1.at(100)<<'\n';
    return 0;
}