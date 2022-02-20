#include "std_facilities.h"
bool is_palindrome(const string& s){
    bool ret=true;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            ret=false;
            break;
        }
    }
    return ret;
}   
//实际上传数组等同于穿指针
//n是字符的个数，不算上c字符串末尾的0
bool is_palindrome(const char s[],int n){
    bool ret=true;
    int first=0;
    int last=n-1;
    while(first<last){
        if(s[first]!=s[last]){
            ret=false;
            break;
        }
        first++;
        last--;
    }
    return ret;
}
int main(){
    bool p=is_palindrome("nii",3);
    cout<<p<<'\n';
    return 0;
}