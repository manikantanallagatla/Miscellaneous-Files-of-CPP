#include<iostream>
using namespace std;
int main(){
	int a[] = {10,20,30};
	int **ptr;
	int * p[] = {a,a+1,a+2};
	ptr = p;
	**ptr++;
	cout<<ptr-p<<"\t"<<*ptr-a<<"\t"<<**ptr<<endl;
	*++*ptr;
	cout<<ptr-p<<"\t"<<*ptr-a<<"\t"<<**ptr<<endl;
	++**ptr;
	cout<<ptr-p<<"\t"<<*ptr-a<<"\t"<<**ptr<<endl;
}
