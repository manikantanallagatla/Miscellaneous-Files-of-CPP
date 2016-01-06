#include<iostream>
using namespace std;
int main(){
	int answer = 0;
	for(int i = 3;i<1000;i = i+3){
		answer+=i;
	}
	for(int i = 5;i<1000;i = i+5){
		answer+=i;
	}
	for(int i = 15;i<1000;i = i+15){
		answer-=i;
	}
	cout<<answer;
}
