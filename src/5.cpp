#include "std_facilities.h"
int main(){
	string previous="";
	string current;
	int cnt=0;
	while(cin>>current){
		++cnt;
		if(current==previous){
			cout<<"cnt:"<<cnt<<" repeat word:"<<current<<'\n';
		}
		previous=current;
	}
	return 0;
}
