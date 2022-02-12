#pragma once
#include "std_facilities.h"
enum Step{
	BLANK,
	BLACK,
	WHITE
};
class Chess{
public:
	Chess();
	void put(int x,int y);
	int get_value(Step s);
	void print();
	Step who_is_next();
	void regret();
private:
	Step* map;
	vector<int> history;
	Step next;
	Step get(int x,int y);
	void go_back();
};
