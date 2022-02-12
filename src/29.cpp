#include "std_facilities.h"
int main(){
	char ch;
	int sum=0;
	int temp=0;
	int x=1;
	while(cin>>ch){
		if(ch>='0'&&ch<='9'){
			sum=temp;
			sum+=narrow_cast<int>(ch-'0');
			temp=sum*10;	
		}
	}
	cout<<"result is "<<sum<<'\n';
	return 0;
}
