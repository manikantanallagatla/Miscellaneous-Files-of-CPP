#include<iostream>
#include<string>
using namespace std;
int main(){
	int answer = 0;
	int x;
	for(int i = 1;i<1000&&(answer == 0);i++){
		for(int j = 1;j<1000&&(answer == 0);j++){
			if(i*i+j*j == (1000-i-j)*(1000-i-j)){
				answer = 1;
				x = i*j*(1000-i-j);
			}
		}
	}
	if(answer == 1){
		cout<<x;
	}
	
}
