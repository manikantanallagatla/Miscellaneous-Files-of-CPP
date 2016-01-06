#include<iostream>
using namespace std;
int main(){
	//int * ptr;
	//cout<<*ptr;
	
    cout<<(int)5.9<<endl;;
    int a(9);
	void * p;
	p = &a;
	int * q = static_cast<int*>(p);
	cout<<*q;
}
