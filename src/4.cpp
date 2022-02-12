#include "std_facilities.h"
int main(){
	string previous="";
	string current;
	while(cin>>current){
		if(current==previous){
			cout<<"repeat word:"<<current<<'\n';
		}
		previous=current;
	}
	return 0;
}
