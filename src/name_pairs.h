#pragma once
#include "std_facilities.h"
class Name_pairs{
	public:
		Name_pairs(){}
		void read_name();
		void read_ages();
		void print() const;
		void sort1();
		class Nomatch{};
	private:
		vector<string> name;
		vector<double> age;
};
