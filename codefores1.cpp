#include<iostream>
using namespace std;
int main(){
	long long int n,m,a;
	cin>>n>>m>>a;
	int x,y;
	if(n%a == 0){
		x = n/a;
	}
	else{
		x = n/a+1;
	}
	if(m%a == 0){
		y = m/a;
		//y--;
	}
	else{
		y = m/a+1;
		//y--;
	}
	cout<<x*y<<endl;
	
}
