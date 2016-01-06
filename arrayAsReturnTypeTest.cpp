#include<iostream>
using namespace std;
int* fillarr(int arr[]){
	int b[5] = {1,0,1,0,1};
	return b;
}
int main(){
	int a[10];
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	int *b =fillarr(a);
	for(int i=0;i<5;i++){
		cout<<b[i]<<endl;
	}
}
