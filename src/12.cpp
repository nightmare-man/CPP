#include "std_facilities.h"
int main(){
	vector<int> v={1,2,3,4,5};
	for(int c: v){
		v.push_back(9);
	}
	for(int c:v){
		cout<<c<<'\n';
	}
	return 0;

}
