#include "library.h"
int main(){
    Library a;
    try{
        using namespace Chrono;
        a.add_book(Book{"12-12-12-x","平凡的世界1","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.add_book(Book{"12-13-12-x","平凡的世界2","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.add_book(Book{"12-12-13-x","平凡的世界3","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.add_book(Book{"12-11-12-x","平凡的世界4","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.add_book(Book{"12-9-12-x","平凡的世界5","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.add_patron(Patron{"lsm",1001});
        a.rent_book(Patron{"lsm",1001},Book{"12-9-12-x","平凡的世界5","路遥",Date{1998,Month::apr,12},Genre::fiction});
        //a.rent_book(Patron{"lsm",1001},Book{"12-9-12-x","平凡的世界5","路遥",Date{1998,Month::apr,12},Genre::fiction});
        a.print_history();
        cout<<a;
    }catch(Library::Lexception e){
        cout<<"错误:"<<e.msg;
        return 1;
    }catch(...){
        cout<<"其他异常\n";
        return 2;
    }
    return 0;
}