#include "std_facilities.h"
struct Reading{
    int hour;
    double temperature;
};
istream& operator>>(istream& is,Reading& r){
    is>>r.hour>>r.temperature;
    return is;
}
void my_swap(vector<Reading>& v,int a,int b){
    Reading temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void my_sort(Vector<Reading>& v){
    for(int i=1;i<v.size();i++){
        for(int j=i;j-1>=0;j--){
            if(v[j].temperature<v[j-1].temperature){
                my_swap(v,j,j-1);
            }
        }
    }
}
void my_print(const vector<Reading>& v){
    for(const Reading& x:v){
        cout<<'('<<x.hour<<','<<x.temperature<<")\n";
    }
}
int main(){
    vector<Reading> v;
    const string inFile="raw_temps.txt";
    ifstream ist{inFile};
    if(!ist) error("open file faile\n");
    for(Reading x;ist>>x;){
        v.push_back(x);
    }
    //my_print(v);
    my_sort(v);
    double sum=0;
    for(Reading x:v){
        sum+=x.temperature;
    }
    cout<<"average is:"<<sum/v.size()<<" mid is:"<<v[v.size()/2].temperature<<'\n';
    //my_print(v);
    return 0;
}