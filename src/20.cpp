#include "std_facilities.h"
int main(){
	vector<int> v(0);
	for(int i;cin>>i;){
		v.push_back(i);
	}
	for(int i=0;i<=v.size();i++){
		cout<<v[i]<<'\n';
	}
	return 0;
}
