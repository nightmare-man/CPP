#include "std_facilities.h"
int main(){
	Vector<string> dislike={"wo","bu","xi","huan"};
	cout<<"type some thing:\n";
	for(string temp;cin>>temp;){
		bool find=false;
		for(string x:dislike){
			if(x==temp){
				find=true;
				break;
			}
		}
		if(find) cout<<"BLEEP\n";
		else cout<<temp<<'\n';
	}
	return 0;
}
