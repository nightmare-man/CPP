#include "std_facilities.h"
int main(){
	constexpr double pi=3.1415926;
	double len=0;
	cout<<"enter len:"<<'\n';
	cin>>len;
	double s=len*len*pi;
	cout<<"square is :"<<s<<'\n';
	return 0;
}
