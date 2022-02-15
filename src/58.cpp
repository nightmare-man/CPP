#include "std_facilities.h"
int main(){
	int a1=100;
	int b=101;
	int* p1=&a1;
	int* p2=&b;
	int* p3=new int[2];
	double a=2.3;
	int* p4=reinterpret_cast<int*>(&a);
	vector<string> v{vector<string>{100,"nihao"}};
	cout<<p1<<'\n';
	cout<<p2<<'\n';
	cout<<p3<<'\n';
	cout<<*p3<<" "<<*(p3+1)<<" "<<*(p3+2)<<'\n';
	cout<<p3[0]<<" "<<p3[1]<<" "<<p3[2]<<'\n';
	cout<<*p4<<'\n';
	return 0;
}
