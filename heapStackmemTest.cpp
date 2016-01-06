#include<iostream>
using namespace std;
int main(){
	long* ptr = new(nothrow)long(10^9);
	if(ptr!=0){
		cout<<"Successful";
	}
	else{
		cout<<"Not Successful";
	}
}
