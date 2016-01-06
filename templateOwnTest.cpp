#include<iostream>
using namespace std;
template<class T>
void swapp(T &a,T &b){
	T temp = a;
	a = b;
	b = temp;
}
main(){
int a(5),b(10);
swapp<int>(a,b);
cout<<a<<"  "<<b<<endl;	
}
