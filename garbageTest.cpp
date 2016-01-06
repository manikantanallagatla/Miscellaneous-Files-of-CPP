#include<iostream>
using namespace std;
int main(){
	int b[5];
	for(int i=0;i<5;i++)
	cout<<b[i]<<endl;
	int a[3][3];
	int k(1);
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
		  a[i][j] = k;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){
		cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}
