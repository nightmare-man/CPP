
#include "std_facilities.h"
#include "book.h"
int main(){

	try{
		Book b{"123-123-123-x","XCODE","lsm",Chrono::Date{2012,Chrono::Month::jan,20},Genre::nofiction};

		cout<<b;
	}catch(Book::Bexception e){
		cout<<e.msg;
		return 1;
	}catch(...){
		cout<<"other exception\n";
		return 2;
	}
	
	
	return 0;
}
