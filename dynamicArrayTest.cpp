#include<iostream>
using namespace std;
int main(){
	int * n;
	int n1;
	cin>>n1;
	n = new int[n1];
	for(int i=0;i<n1;i++){
		n[i] = i;
	}
	for(int i=0;i<n1;i++){
		cout<<n[i];
	}
}
