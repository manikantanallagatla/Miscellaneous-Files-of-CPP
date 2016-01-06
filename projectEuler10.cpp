#include<iostream>
using namespace std;
int isPrime(int x){
	for(int i = 2;i*i<=x;i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	long sum = 0;
	long x = 2000000;
	for(int i = 2;i<x;i++){
		if(isPrime(i) == 1){
			sum = sum+i;
			cout<<sum<<endl;;
		}
	}
	cout<<"FinalSum is "<<sum<<endl;
}
