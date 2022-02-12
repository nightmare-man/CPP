#include "std_facilities.h"
class Bad_area{};
int area(int length,int width){
	if(length<=0||width<=0){
		throw Bad_area{};
	}
	return length*width;
}
int framed_area(int x,int y){
	return area(x-2,y-2);
}
int main(){
	try{
	int x=-1;
	int y=2;
	int z=4;
	int area1=area(x,y);
	int area2=framed_area(1,z);
	int area3=framed_area(y,z);
	cout<<area3<<'\n';
	double ratio=double(area1)/area3;
	cout<<ratio<<'\n';
	}catch(Bad_area){
		cout<<"oops! bad argument to area()\n";
	}
	return 0;
}
