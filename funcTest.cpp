#include<iostream>
using namespace std;
int div(int x,int y);
int main(){
	int a(5),b(3);
	cout<<div(a,b);
}
int div(int x,int y){
	return x/y;
}
