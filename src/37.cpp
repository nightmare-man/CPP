#include "std_facilities.h"
vector<int>& reverse(const vector<int>& v){
	static vector<int> vv;
	for(int i=v.size()-1;i>=0;i--){
		vv.push_back(v[i]);
	}
	return vv;
}
void swap(int& a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void print(const vector<int>& v){
	for(int x:v){
		cout<<" "<<x;
	}
	cout<<'\n';
}
void reverse1(vector<int>& v){
	for(int i=0;i<v.size()/2;i++){
		swap(v[i],v[v.size()-1-i]);
	}
}
int main(){
	vector<int> v{1,2,3,4,5,6};
	vector<int>& v1=reverse(v);
	print(v);
	cout<<"now v1\n";
	print(v1);
	reverse1(v);
	cout<<"now v\n";
	print(v);
	return 0;
}
