#include "std_facilities.h"
int main(){
	for(double a,b;cin>>a>>b;){
		cout<<a<<" "<<b<<'\n';
		double c=0;
		if(a>b){
			c=b;
			b=a;
			a=c;	
		}
		if(b==a){
			cout<<"the numbers are equal\n";
		}else{
			cout<<"the smaller is:"<<a<<" the larger is:"<<b<<'\n';
			if(b-a<0.01){
				cout<<"the numbers are almost equal\n";
			}
		}

	}

	return 0;
}

