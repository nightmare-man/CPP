#include "std_facilities.h"
void swap(int &a,int &b){
	int c=b;
	b=a;
	a=c;
}
int main(){
	int a=100;
	int b=200;
	swap(a,b);
	cout<<a<<"  "<<b<<'\n';
	return 0;
}
