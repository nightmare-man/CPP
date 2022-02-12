#pragma once
#include "Chrono.h"
enum class Genre{
	fiction,nofiction,periodical,biography,children	
};
class Book{
	public:
		class Bexception{
			public:
				Bexception(string m):msg{m}{}
				string msg;
		};
		Book():borrowed{false},isbn{"n-n-n-x"},name{"name"},author{"author"},copyright{Chrono::Date{}}{}
		Book(string i,string n,string a,Chrono::Date d,Genre t);
		string Isbn()const{return isbn;}
		string Name()const{return name;}
		string Author()const{return author;}
		Genre Type()const{return type;}
		Chrono::Date Copyright()const{return copyright;}
		bool Borrowed()const{return borrowed;}
		void Rent();
		void Return();

	private:
		Genre type;
		string isbn;
		string name;
		string author;
		Chrono::Date copyright;
		bool borrowed;
};
int read_num(string s,int& idx);
bool is_valid_isbn(string isbn);
bool operator==(const Book& a,const Book& b);
bool operator!=(const Book& a,const Book& b);
ostream& operator<<(ostream& os,const Book& a);
