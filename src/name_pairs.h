#pragma once
#include "std_facilities.h"
class Name_pairs{
	public:
		Name_pairs(){}
		void read_name();
		void read_ages();
		void sort1();
		void print()const;
		class Nomatch{};
	private:
		vector<string> name;
		vector<double> age;
};
ostream& operator<<(ostream& os,const Name_pairs& a);
bool operator==(const Name_pairs& a,const Name_pairs& b);
bool operator!=(const Name_pairs& a,const Name_pairs& b);
