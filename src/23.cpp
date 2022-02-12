#include "std_facilities.h"
int main(){
    vector<double> temps;
    for(double temp;cin>>temp;){
        temps.push_back(temp);
    }
    double sum=0;
    double high_temp=-99999;
    double low_temp=99999;
    for(double x:temps){
        if(x>high_temp){
            high_temp=x;
        }
        if(x<low_temp){
            low_temp=x;
        }
        sum+=x;
    }
    cout<<"high temperature:"<<high_temp<<'\n';
    cout<<"low temperature:"<<low_temp<<'\n';
    cout<<"average temperature:"<<sum/temps.size()<<'\n';
    return 0;
}