#include "std_facilities.h"
int main(){
    const string outFile="raw_temps.txt";
    ofstream ost{outFile};
    if(!ost) error("open file fail\n");
    for(int i=0;i<50;i++){
        ost<<i<<" "<<static_cast<double>(i)*3.14<<'\n';
    }
    return 0;
}