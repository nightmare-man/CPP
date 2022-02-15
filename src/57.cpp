#include "std_facilities.h"
int main(){
    cout<<"type input file name:\n";
    string inFile;
    cin>>inFile;
    ifstream ist{inFile};
    if(!ist) error("open file error!\n");
    int sum=0;
    for(int n=0;ist>>n;){
        sum+=n;
    }
    cout<<"sum:"<<sum<<'\n';
    return 0;
}