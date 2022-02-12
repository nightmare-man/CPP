#include "std_facilities.h"
int main(){
    try{
	    cin<<"Success!\n";
    }catch(exception& e){
        cerr<<"error"<<e.what()<<'\n';
        return 1;
    }catch(...){
        cerr<<"unknow exception\n";
        return 2;
    }

}
