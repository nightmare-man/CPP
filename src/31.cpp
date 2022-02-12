#include "std_facilities.h"
void print(const vector<int>& a ){
	for(int x:a){
	cout<<x<<'\n';
	}
}
int main(){
	vector<int> temps(100);
	print(temps);
	return 0;
}
