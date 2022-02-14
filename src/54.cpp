#include "std_facilities.h"
void input0(){
    cout<<"type 1-10(inclusive)\n";
    int n=0;
    while(cin>>n&&!(n>=1&&n<=10)){
        cout<<"not in 1-10;try again:\n";
    }
}
void input1(){
    cout<<"type 1-10(inclusive)\n";
    int n=0;
    while(true){
        cin>>n;
        if(cin){
            if(n>=1&&n<=10) {
                cout<<"you input num is "<<n<<'\n';
                break;
            };
            cout<<"not in 1-10,try again\n";
        }
        else if(cin.fail()){
            cin.clear();
            cout<<"not a num,try again:\n";
            for(char ch;cin>>ch&&!(isdigit(ch));){
                //读取所有非数字字符，跳过他们
            }
            if(!cin) error("no input\n");
            cin.unget();//将该数字字符放回
        }else{
            error("no input\n");
        }
    }
}
void skip_to_int(){
    if(cin.fail()){
        cin.clear();
        cout<<"not a num,try again:\n";
        for(char ch;cin>>ch&&!isdigit(ch);){

        }
        if(!cin) error("no input\n");
        cin.unget();
        return;
    }
    error("no input\n");
}
void input2(){
    int n=0;
    while(true){
        cin>>n;
        if(cin){
            if(n>=1&&n<=10){
                cout<<"you num is "<<n<<'\n';
                break;
            }else{
                cout<<"not in 1-10,try again\n";
            }
        }
        else{
            skip_to_int();
        }
    }
}
int main(){
    input2();
    return 0;
}