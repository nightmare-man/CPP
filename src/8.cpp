#include "std_facilities.h"
int main(){
	int a{2000};
	char c{a};
	int b{c};
	if(a!=b) cout<<"oops!:"<<a<<"!="<<b<<'\n';
	else cout<<"Wow"<<'\n';
	return 0;
}
