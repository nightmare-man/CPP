#include "std_facilities.h"
int main(){
	cout<<"Expression:";
	int lval=0;
	int rval=0;
	char op;
	int res;
	cin>>lval>>op>>rval;
	if(op=='+'){
		res=lval+rval;	
	}else if(op=='-'){
		res=lval-rval;
	}
	cout<<"result:"<<res<<'\n';
	return 0;
}	
