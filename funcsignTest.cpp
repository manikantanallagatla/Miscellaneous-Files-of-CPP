#include<iostream>
using namespace std;
void swap(int&,int&);
void display(int,int);
int main(){
	int a(5),b(10);
	swap(a,b);
	display(a,b);
}
void swap(int& a,int& b){
	int c = a;
	a = b;
	b = c;
}
void display(int a,int b){
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	//cout<<&a;
}
