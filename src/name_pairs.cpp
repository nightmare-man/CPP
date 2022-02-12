#include "name_pairs.h"
#include "std_facilities.h"
void Name_pairs::read_name(){
	cout<<"type all name:";
	for(string n;cin>>n;){
		if(n=="end") break;
		name.push_back(n);
	}
}
void Name_pairs::read_ages(){
	for(string s:name){
		cout<<"age for "<<s<<":";
		double a;
		
		if(!(cin>>a)) throw Nomatch{};
		age.push_back(a);
	}
}
void Name_pairs::print() const{ 
	for(int i=0;i<name.size();i++){
		cout<<name[i]<<":"<<age[i]<<" ";
	}
	cout<<'\n';
}
ostream& operator<<(ostream& os,const Name_pairs& a){
	a.print();	
}
double get_age(const vector<string>& name,const vector<double>& age,string target){
	for(int i=0;i<name.size();i++){
		if(name[i]==target){
			return age[i];
		}
	}
	throw Name_pairs::Nomatch{};
}
void Name_pairs::sort1(){
	static vector<string> temps;
	static vector<double> tempd;
	temps=name;
	tempd=age;
	sort(name);
	for(int i=0;i<age.size();i++){
		age[i]=get_age(temps,tempd,name[i]);
	}
}
