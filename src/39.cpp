#include "chess.h"
#include "std_facilities.h"
int main(){
	Chess s;
	int x=0,y=0;
	while(true){
		Step next=s.who_is_next();
		s.print();
		cout<<"next is "<<((next==BLACK)?"black":"white")<<'\n';
		cout<<">";
		cin>>x>>y;
		if(x==y&&x==15){
			s.regret();
		}
		else{
			s.put(x,y);
			cout<<"after this step,you value is "<<s.get_value(next)<<'\n';	
		}
		
	}
	return 0;
}
