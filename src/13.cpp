#include "std_facilities.h"
int main(){
	vector<double> temps;
	for(double temp;cin>>temp;){
		temps.push_back(temp);
	}
	double sum=0;
	for(double x:temps) sum+=x;
	cout<<"average of temps is "<<sum/temps.size()<<'\n';
	sort(temps);
	cout<<"Median of temps is "<<temps[temps.size()/2]<<'\n';
	return 0;

}
