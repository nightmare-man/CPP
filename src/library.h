#pragma once
#include "string"
#include "vector"
#include "book.h"
#include "patron.h"
#include "Chrono.h"
struct Transaction{
    Book& b;
    Patron& p;
    Chrono::Date d;
};
class Library{
    public:
        class Lexception{
            public:
                Lexception(string m):msg{m}{}
                string msg;
        };
        Library(){}
        int book_num()const{return books.size();}
        int patron_num()const{return patrons.size();}
        int history_num()const{return history.size();}
        void add_book(Book b);
        void add_patron(Patron p);
        void rent_book(Patron p,Book b);
        void print_history()const;
    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> history;
};
ostream& operator<<(ostream& os,const Library& b);
