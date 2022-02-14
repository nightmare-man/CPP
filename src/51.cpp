#include "std_facilities.h"
struct Reading{
    int hour;
    double temperature;
};
int main(){
    string inFile;
    string outFile;
    Vector<Reading> data;
    cout<<"type input file name:\n";
    cin>>inFile;
    cout<<"type output file name:\n";
    cin>>outFile;
    ifstream ist{inFile};
    if(!ist) error("开打文件失败\n");
    int h=0;
    double t=0.0;
    while(ist>>h>>t){
        if(h<0||h>24) error("out of range\n");
        data.push_back(Reading{h,t});
    }
    ofstream ost{outFile};
    if(!ost) error("打开文件失败\n");
    for(Reading x:data){
        ost<<x.hour<<','<<x.temperature<<'\n';
    }
    return 0;
}