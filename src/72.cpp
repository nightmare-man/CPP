#include "std_facilities.h"
char* My_strdup(const char* s){
    const char* p=s;
    int cnt=1;
    while(*p!=0){
        p++;
        cnt++;
    }
    char* ret=new char[cnt];
    for(int i=0;i<cnt;i++){
        ret[i]=s[i];
    }
    return ret;
}
char* My_findx(const char* s,const char* x){
    const char* ret=nullptr;
    for(const char *p1=s;*p1!=0;p1++){
        bool match=true;
        for(const char*p2=x;*p2!=0;p2++){
            if(*(p1+static_cast<int>(p2-x))!=*p2){
                match=false;
                break;
            }
        }
        if(match){
            ret=p1;
            break;
        }
    }
    return const_cast<char*>(ret);
}
int My_strcmp(const char* s1,const char* s2){
    while((*s1)!=0&&(*s2)!=0){
        if(*s1==*s2){
            s1++;
            s2++;
        }else if(*s1>*s2){
            return 1;
        }else return -1;
    }
    if(*s1==0&&*s2==0){
        return 0;
    }
    if(*s1==0) return -1;
    return 1;
}
string cat_dot(const string& s1,const string& s2){
    return s1+"."+s2;
}
char* cat_dot1(const char* s1,const char* s2,char s){
    int len1=0;
    int len2=0;
    const char* p1=s1;
    const char* p2=s2;
    while(*p1!=0){
        p1++;
        len1++;
    }
    while(*p2!=0){
        p2++;
        len2++;
    }
    char* ret=new char[len1+len2+2];
    for(int i=0;i<len1;i++){
        ret[i]=s1[i];
    }
    ret[len1]=s;
    for(int i=0;i<len2;i++){
        ret[len1+1+i]=s2[i];
    }
    ret[len1+len2+1]=0;
    return ret;
}
int main(){
    char*p=cat_dot1("nihao","lsm",'|');
    printf("%s",p);
    delete[] p;
    return 0;
}