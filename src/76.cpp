#include "Mvector.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;

int main(){
    Mvector<int> p(10);
    cout<<p[0]<<'\n';
    return 0;
}