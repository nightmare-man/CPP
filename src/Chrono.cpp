#include "Chrono.h"
namespace Chrono{
    Date::Date(int yy,Month mm,int dd)
        :y{yy},m{mm},d{dd}{
            if(!is_date(yy,mm,dd))throw Invalid{};
        }
    const Date& default_date(){
        static Date dd{2001,Month::jan,1};
        return dd;
    }
    Date::Date():y{default_date().year()},m{default_date().month()},
    d{default_date().day()}{

    }
    void Date::add_day(int n){

    }
    void Date::add_month(int n){

    }
    void Date::add_year(int n){
        if(m==Month::feb&&d==29&&!leapyear(y+n)){
            m=Month::mar;
            d=1;
        }
    }
    bool is_date(int y,Month m,int d){
        if(d<0) return false;
        if(m<Month::jan||m>Month::dec) return false;
        int days_in_month=31;
        switch (m)
        {
        case Month::feb:
            days_in_month=(leapyear(y)?29:28);
            break;
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov:
            days_in_month=30;
            break;
        default:
            break;
        }
        if(d>days_in_month) return false;
        return true;
    }
    bool leapyear(int n){

    }
    bool operator==(const Date& a,const Date& b){
        return a.year()==b.year()&&a.month()==b.month()&&a.day()==b.day();
    }
    bool operator!=(const Date& a,const Date& b){
        return !(a==b);
    }
    ostream& operator<<(ostream& os,const Date& d){
        return os<<'('<<d.year()<<',' << static_cast<int>(d.month())<<','<<d.day()<<')';
    }
    istream& operator>>(istream& is,Date& dd){
        int y,m,d;
        char ch1,ch2,ch3,ch4;
        is>>ch1>>y>>ch2>>m>>ch3>>d>>ch4;
        if(!is) return is;
        if(ch1!='('||ch2!=','||ch3!=','||ch4!=')'){
            is.clear(ios_base::failbit);
            return is;//如果格式失败，返回已经读取的bit流    
        }
        dd=Date(y,Month(m),d);
        return is;
    }
    enum class Day{
        sunday,monday,tuesday,wednesday,thursday,friday,saturday
    };
    Day day_of_week(const Date& d){

    }
    Date next_Sunday(const Date& d){

    }
    Date next_weekday(const Date& d){
        
    }
}