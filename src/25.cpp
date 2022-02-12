#include "std_facilities.h"
class Fexception{};
void f(double a,double b,double c){
	double temp=b*b-4*a*c;
	if(temp<0){
		throw Fexception{};
	}
	if(temp==0){
		cout<<"x is :"<<(-b)/2/a<<'\n';
	}else{
		cout<<"x1 is:"<<(-b+sqrt(temp))/2/a<<" x2 is:"<<(-b-sqrt(temp))/2/a<<'\n';
	}

}
int main(){
	
}
