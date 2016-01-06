#include<iostream>
using namespace std;
int isPrime(int prime){
	for(int i = 2;i*i<= prime;i++){
		if(prime%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int prime = 2;
	int index = 1;
	while(index != 10001){
		prime++;
		if(isPrime(prime) == 1){
			index++;
		}
	}
	cout<<prime<<endl;
}
