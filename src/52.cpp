#include "std_facilities.h"
int main(){
    int i=0;
    cin>>i;
    if(!cin){
        if(cin.bad()) error("cin is bad\n");
        if(cin.eof()){
            cout<<"input end\n";
            return 1;
            //eof也是一种输入
        }
        if(cin.fail()){
            cout<<"非数字，清除了输入流错误\n";
            cin.clear();//格式错误 
        }
    }
    return 0;
}