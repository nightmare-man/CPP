#pragma once
#include "string"
using namespace std;
class Patron{
    public:
        Patron(string n,int i):name{n},id{i},debet{0}{}
        Patron(string n,int i,double d):name{n},id{i},debet{d}{}
        string Name()const{return name;}
        int Id()const{return id;}
        double Debet()const{return debet;}
        void SetDebet(double d);
    private:
        string name;
        int id;
        double debet;
};
bool InDebet(const Patron& p);
int valid_id();