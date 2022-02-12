#include "name_pairs.h"
int main(){
	Name_pairs n;
	n.read_name();
	try
	{
		n.read_ages();
		cout<<"print:\n";
		cout<<n;
		cout<<"sort:\n";
		n.sort1();
		cout<<n;
	}catch(Name_pairs::Nomatch e){
		cout<<"no age match!\n";
		return 1;
	}catch(...){
		cout<<"other exception!\n";
		return 2;
	} 
	return 0;
}
