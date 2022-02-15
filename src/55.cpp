#include "std_facilities.h"
const int not_a_reading=-777;
const int not_a_month=-1;//未读取的都用这两个表示
struct Day{
    vector<double> hour{vector<double>(24,not_a_reading)};
    //用一个vector初始化另一个vector，使用(数量，初始值)批量初始化
};
struct Month{
    int month{not_a_month};
    vector<Day> day{32};//当用{}只有一个数字且vector不是int时，该数字为
    //vector的个数
};
struct Year{
    int year;
    vector<Month> month{12};
};
struct Reading{
    int day;
    int hour;
    double temperature;
};
istream& operator>>(istream& is,Reading& r){
    char ch1;
    if(is>>ch1&&ch1!='('){
        //cout<<"未读取到数值\n";
        //如果is直接没读到，还是会在后面进入error
        is.unget();
        is.clear(ios_base::failbit);
        return is;//将该字符收回，设置为fail
    }
    //cout<<"开始读取数值\n";
    char ch2;
    int d;
    int h;
    double t;
    is>>d>>h>>t>>ch2;
    if(!is||ch2!=')'){
        error("bad reading\n");//这里直接error，想将已经读的数字退回去比较麻烦
    }
    r.day=d;
    r.hour=h;
    r.temperature=t;
    return is;
}
vector<string> month_input{
    "jan","feb","mar","apr","may","jun",
    "jul","aug","sep","oct","nov","dec"
};
int month_to_int(string m){
    int ret=-1;
    for(int i=0;i<month_input.size();i++){
        if(month_input[i]==m){
            ret=i;
            break;
        }
    }
    return ret;
}
bool is_valid(Reading x){
    return true;
}
void end_of_loop(istream& is,char e,string msg){
    if(is.fail()){
        is.clear();
        char ch;
        if(is>>ch&&ch==e) return;
        error(msg);
    }
}
istream& operator>>(istream& is,Month& m){
    char ch=0;
    if(is>>ch&&ch!='{'){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    //cout<<"开始读入月份\n";
    string month_marker;
    string mm;
    is>>month_marker>>mm;
    if(!is||month_marker!="month")error("bad start of month");
    int n=month_to_int(mm);
    if(n==-1) error("invalid month\n");
    m.month=n;
    int duplicates=0;
    int invalids=0;
    //cout<<"读入月份成功:"<<n<<"\n";
    for(Reading r;is>>r;){
        //cout<<"数值循环开始\n";
        if(is_valid(r)){
            if(m.day[r.day].hour[r.hour]!=not_a_reading){
                duplicates++;
            }
            m.day[r.day].hour[r.hour]=r.temperature;
        }else{
            invalids++;
        }
    }
    if(invalids) error("invalid readings in month\n");
    if(duplicates) error("duplicate reading in month\n");
    end_of_loop(is,'}',"bad end of month\n");
    //cout<<"读取月份结束\n";
    return is;
}
istream& operator>>(istream& is,Year& y){
    char ch;
    is>>ch;
    if(!is) return is;
    if(is&&ch!='{'){
        //cout<<"not { of year\n";
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    //if(ch=='{') cout<<"真的是年份开始的标志\n";
    //cout<<"开始读取年份\n";
    string year_mark;
    int year;
    is>>year_mark>>year;
    if(!is||year_mark!="year"){
         error("bad start of year\n");

    }
    y.year=year;
    while(true){
        Month m;
        if(!(is>>m)) break;
        y.month[m.month]=m;//这里是深拷贝还是浅拷贝不得而知
    }
    end_of_loop(is,'}',"bad end of year\n");
    //cout<<"读取年份结束\n";
    return is;
}
void print_month(ostream& os,const Month &m){
    os<<"\tmonth:"<<month_input[m.month]<<'\n';
    for(int i=0;i<m.day.size();i++){
        os<<"\t[day:"<<i+1;
        for(int j=0;j<m.day[i].hour.size();j++){
            if(m.day[i].hour[j]!=not_a_reading){
                os<<" h"<<j<<" t"<<m.day[i].hour[j];
            }
        }
        os<<"]\n";
    }
}
void print_year(ostream& os, const Year &y){
    os<<"year:"<<y.year<<'\n';
    for(const Month& m:y.month){
        if(m.month!=not_a_month) print_month(os,m);
    }
}
int main(){
    ifstream ist{"in.dat"};
    if(!ist) error("open file fail\n");
    ist.exceptions(ist.exceptions()|ios_base::badbit);//bad状态直接异常
    ofstream ost("out.dat");
    if(!ost) error("open file fail\n");
    vector<Year> ys;
    while(true){
        Year r;
        if( !(ist>>r)) break;
        ys.push_back(r);
    }
    cout<<"read "<<ys.size()<< " years of readings \n";
    for(const Year& y:ys){
        print_year(ost,y);
    }
    return 0;
}