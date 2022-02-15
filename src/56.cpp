#include "std_facilities.h"
struct Point{
    double x;
    double y;
};
void print(const vector<Point>& v){
    for(const Point& x:v){
        cout<<x.x<<","<<x.y<<"\n";
    }
}
int main(){
    vector<Point> original_points;
    cout<<"type 7 point:\n";
    Point p;
    for(int i=0;i<7;i++){
        cin>>p.x>>p.y;
        original_points.push_back(p);
    }
    print(original_points);
    return 0;
}