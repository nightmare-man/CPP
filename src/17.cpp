#include "std_facilities.h"
int main(){
	double a=0,b=0,c=0;
	cout<<"enter a b c\n";
	cin>>a>>b>>c;
	double temp=b*b-4*a*c;
	if(temp<0){
		cout<<"no solution\n";
	}else if(temp==0){
		cout<<"solution is:"<<(-b)/2/a<<'\n';
	}else{
		double temp1=sqrt(temp);
		double x1=(-b+temp1)/(2*a);
		double x2=(-b-temp1)/(2*a);
		cout<<"solution is:"<<x1<<" and "<<x2<<'\n';
	}
	return 0;
}
