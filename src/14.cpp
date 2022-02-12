#include "std_facilities.h"
int main(){
	vector<string>dict(0);
	for(string temp;cin>>temp;) dict.push_back(temp);
	sort(dict);
	for(int i=0;i<dict.size();++i){
		if(i==0||dict[i]!=dict[i-1]){
			cout<<dict[i]<<'\n';
		}
	}
	return 0;
}
