#include "std_facilities.h"
vector<int> fun(){
	vector<int>ret {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16};
	return ret;
}
vector<int>& fun1(){
	static vector<int> ret {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16};
	return ret;
}
int main(){
	vector<int> p;
	for(int i=0;i<20000000;i++){
	
			p=fun();
	}
	cout<<p[0]<<"end\n";
	return 0;
}
