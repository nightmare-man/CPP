#include "std_facilities.h"
void f(vector<int> v){
	v[0]=-1;
}
int main(){
	vector<int> v{1,2,3};
	f(v);
	cout<<v[0]<<'\n';
	return 0;
}
