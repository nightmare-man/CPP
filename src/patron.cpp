#include "patron.h"
int valid_id(){
    static int ret=10001;
    ret++;
    return ret;
}

bool InDebet(const Patron& p){
    return p.Debet()>0;
}
void Patron::SetDebet(double n){
    if(n<0) n=0;
    debet=n;
}