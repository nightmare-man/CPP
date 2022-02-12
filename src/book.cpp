#include "book.h"
#include "std_facilities.h"
#include <cctype>
int read_num(string s,int& idx){
	int sum=0;
	int temp=0;
    int cnt=idx;
	for(int i=idx;i<s.size();i++){
		if(s[i]>'9'||s[i]<'0'){
			break;
		}
		cnt++;
		sum=temp;
		sum+=static_cast<int>(s[i]-'0');
        temp=sum*10;
	}
    idx=cnt;
	return sum;
}
bool is_valid_isbn(string s){
    int idx=0;
    if(read_num(s,idx)==0) return false;
    if(s[idx]!='-') return false;
    idx++;
    if(read_num(s,idx)==0) return false;
    if(s[idx]!='-') return false;
    idx++;
    if(read_num(s,idx)==0) return false;
    if(s[idx]!='-') return false;
    idx++;
    if(isalnum(s[idx])==0) return false;
    return true;
}
Book::Book(string i,string n,string a,Chrono::Date d,Genre t){
    if(!is_valid_isbn(i)) throw Bexception{"非法isbn\n"};
    isbn=i;
    author=a;
    name=n;
    copyright=d;
    type=t;
    borrowed=false;
}
void Book::Rent(){
    if(borrowed) throw Bexception{"该书已借出\n"};
    else{
        borrowed=true;
    }
}
void Book::Return(){
    if(!borrowed) throw Bexception{"无法归还\n"};
    else{
        borrowed=false;
    }
}
bool operator==(const Book& a,const Book& b){
	return (a.Isbn()==b.Isbn());
}
bool operator!=(const Book& a,const Book& b){
	return !(a==b);
}
ostream& operator<<(ostream& os,const Book& a){
	os<<a.Name()<<" "<<a.Author()<<" "<<a.Isbn()<<" "<<(int)a.Type();
	return os; 
}
