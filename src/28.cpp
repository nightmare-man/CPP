#include "std_facilities.h"
class Token{
public:
	char kind;
	double value;
	Token(char ch):kind(ch),value(0){}
	Token(char ch,double val):kind(ch),value(val){}
};
class Token_stream{
	public:
	Token_stream();
	Token get();
	void putback(Token);
	private:
	bool full{false};
	Token buffer;
};
Token_stream::Token_stream():full(false),buffer(0){

}
void Token_stream::putback(Token t){
	if(full) error("putback into a full buffer\n");
	buffer=t;
	full=true;
}
Token Token_stream::get(){
	if(full){
		full=false;
		return buffer;
	}
	char ch;
	cin>>ch;
	if(ch==';') {
		//cin.putback(ch);
		return Token('9',0);
	}
	switch(ch){
		case '+': case '-': case '*': case '/': case '(': case ')': case '!':
		{
			return Token(ch);
		}
		case '.': case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double d;
			cin>>d;
			return Token('8',d);
		}
		default:
			error("bad token\n");
	}
}
Token_stream ts;
double expression();
double term();
double Ifun();
int Ifun1(int i){
	int sum=1;
	for(;i>0;i--){
		sum*=i;
	}
	return sum;
}
double primary(){
	Token t=ts.get();
	double r=0;
	switch(t.kind){
		case '(':
			{
				double d=expression();
				t=ts.get();
				if(t.kind!=')') error("expect )\n");
				r=d;
				break;
			}
		case '8':
			r=t.value;
			break;
		default:
			error("primary expected!\n");
	}
	t=ts.get();
	if(t.kind=='!'){
		r=Ifun1((int)r);
	}else{
		ts.putback(t);
	}
	return r;
}
int main(){
	double val=0;
	try{

		while(cin){
			Token t=ts.get();
			
			if(t.kind=='9'){
				cout<<"="<<val<<'\n';
			}
			else ts.putback(t);
			val=expression();

		}
	}catch(exception e){
		cerr<<e.what()<<'\n';
		return 1;
	}catch(...){
		cerr<<"exception 2\n";
		return 2;
	}
}
double expression(){
	double left=term();
	Token t=ts.get();
	while(true){
		switch(t.kind){
			case '+':
				left+=term();
				t=ts.get();
				break;
			case '-':
				left-=term();
				t=ts.get();
				break;
			default:
				ts.putback(t);
				return left;//退出大循环
		}
	
	}
}
double term(){
	double left=primary();
	Token t=ts.get();
	while(true){
		switch(t.kind){
			case '*':
				left*=primary();
				t=ts.get();
				break;
			case '/':{
				double d=primary();
				if(d==0) error("divide by zero\n");
				left/=d;
				t=ts.get();
				break;}
			default:
				 ts.putback(t);
				return left;

		}
	}
}

