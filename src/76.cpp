#include "Mvector.h"
#include <iostream>
using namespace std;
int main(){
    Mvector<char> v;
    v.push_back('a');
    cout<<v[0]<<'\n';
    return 0;
}