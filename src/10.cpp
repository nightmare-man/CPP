#include "std_facilities.h"
int main(){
	string operation="";
	double num1=0;
	double num2=0;
	cin>>operation>>num1>>num2;
	if(operation=="+") cout<<num1<<operation<<num2<<"="<<num1+num2<<'\n';
       	else if(operation=="-") cout<<num1<<operation<<num2<<"="<<num1-num2<<'\n';
	else cout<<"unsupport operation:"<<operation<<'\n';
	return 0;	
}
