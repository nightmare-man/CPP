#include "std_facilities.h"
void print(const string& s,const vector<int>& v){
	for(int x: v){
	cout<<x<<s;
	}
	cout<<'\n';
}
void fibonacci(int x,int y,vector<int>& v,int& n){
	int temp;
	for(int i=0;i<n;i++){
		temp=x+y;
		if(temp<0){
			n=i+2;
			break;
		}
		v.push_back(temp);
		x=y;
		y=temp;
	}
}
int main(){
	vector<int> temp;
	int n=100;
	fibonacci(1,1,temp,n);
	print(" ",temp);
	cout<<"there are "<<n<<" fibonaccis\n";
	return 0;
}
