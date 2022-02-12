#include "std_facilities.h"
int main(){
	cout<<"Expression(end with x):";
	int lval=0,rval=0;
	cin>>lval;
	if(!cin) error("no first operand\n");
	for(char op;cin>>op;){
		if(op!='x'){
			cin>>rval;
		}
		if(!cin){
			error("no second operand\n");
		}
		switch(op){
			case '+':
				lval+=rval;
				break;
			case '-':
				lval-=rval;
				break;
			case '*':
				lval*=rval;
				break;
			case '/':
				lval/=rval;
				break;
			default:
				cout<<"result is "<<lval<<'\n';
				return 0;
		}
	}
	error("bad expression\n");
	return 1;
}
