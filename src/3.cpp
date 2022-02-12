#include "std_facilities.h"
int main(){
	cout<<"please enter two names\n";
	string first;
	string second;
	cin>>first>>second;
	if(first==second) cout<<"that's the same name twice\n";
	else if(first<second) cout<<first<<" is alphabetically before "<<second<<'\n';
	else cout<<first<<" is alphabetically after "<<second<<'\n';
	return 0;
}
