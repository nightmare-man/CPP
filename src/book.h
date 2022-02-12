#pragma once
#include <string>
#include "Chrono.h"
class Book{
	public:
		class Bexception{
			public:
				Bexception(string m):msg{m}{}
				string msg;
		};
		Book():borrowed{false},isbn{"n-n-n-x"},name{"name"},author{"author"},copyright{Chrono::Date{}}{}
		Book(string i,string n,string a,Chrono::Date d);
		string Isbn()const{return isbn;}
		string Name()const{return name;}
		string Author()const{return author;}
		Chrono::Date Copyright()const{return copyright;}
		bool Borrowed()const{return borrowed;}
		void Rent();
		void Return();

	private:
		string isbn;
		string name;
		string author;
		Chrono::Date copyright;
		bool borrowed;
};
int read_num(string s,int& idx);
bool is_valid_isbn(string isbn);
