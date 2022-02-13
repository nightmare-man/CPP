#include "library.h"
void Library::add_book(Book b){
    for(Book x:books){
        if (x==b) throw Lexception{"已存在该书，请勿重复添加\n"};   
    } 
    books.push_back(b);
    cout<<"添加书籍成功："<<b<<'\n';
}
void Library::add_patron(Patron p){
    for(Patron x:patrons){
        if(p.Id()==x.Id()) throw Lexception{"存在该id用户，请勿重复添加\n"};
    }
    patrons.push_back(p);
    cout<<"添加用户成功："<<p.Name()<<'\n';
}
void Library::rent_book(Patron p,Book b){
    bool f1=false;
    bool f2=false;
    Patron& p1=patrons[0];
    Book& b1=books[0];
    for(int i=0;i<patrons.size();i++){
        if(patrons[i].Id()==p.Id()){
            f1=true;
            p1=patrons[i];
            break;
        }
    }
    for(int i=0;i<books.size();i++){
        if(books[i]==b){
            f2=true;
            b1=books[i];
            break;
        }
    }
    if(!f1) throw Lexception{"不存在该用户\n"};
    if(!f2) throw Lexception{"不存在该书\n"};
    if(b1.Borrowed()) throw Lexception{"该书已经被借出\n"};
    if(p1.Debet()>0) throw Lexception{"该用户欠费\n"};
    history.push_back(Transaction{b1,p1,Chrono::Date{2022,Chrono::Month::feb,13}});
    b1.Rent();
    cout<<"借书成功\n";
}
void Library::print_history()const{
    for(Transaction t:history){
        cout<<"借阅者："<<t.p.Name()<<"\t书名:"<<t.b.Name()<<'\n';
    }
}
ostream& operator<<(ostream& os,const Library& b){
    os<<"统计:\n"<<"图书"<<b.book_num()<<"本\n"<<"读者"<<b.patron_num()<<"位\n"
    <<"借阅"<<b.history_num()<<"人次\n";
    return os;
}