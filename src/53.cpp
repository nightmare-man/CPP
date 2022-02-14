#include "std_facilities.h"
//该函数读入数字到vector<int> 自己定义了终结符
void fill_vector(istream& ist,vector<int>& v,string terminator){
    for(int l;ist>>l;) v.push_back(l);
    if(ist.eof()){
        cout<<"input end\n";
        return;
    }
    if(ist.bad()){
        error("ist is bad\n");
    }    
    if(ist.fail()){
        ist.clear();
        string c;
        ist>>c;//将识别错误的bit当作char 看看是不是终结符
        if(c!=terminator){
            ist.unget();//退回该符号
            ist.clear(ios_base::failbit);//重新置为fail状态
            cout<<"非法输入,置fail\n";
            return;
        }
        //终结符，直接读入返回
        cout<<"读取到终结符:"<<terminator<<" 输入结束\n";
    }
}
int main(){
    vector<int> temp;
    string t="end";
    fill_vector(cin,temp,t);
    return 0;
}