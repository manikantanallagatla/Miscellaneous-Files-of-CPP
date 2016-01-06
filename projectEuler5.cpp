#include<iostream>
using namespace std;
int main(){
	int x = 20;
	int answer = 0;
	while(answer == 0){
		answer = 1;
		for(int i = 1;i<21;i++){
			if(x%i!=0){
				answer = 0;
				x++;
				continue;
			}
		}
		
	}
	if(answer == 1){
		cout<<x<<endl;
	}
}
