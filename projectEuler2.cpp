#include<iostream>
using namespace std;
int fibo(int y,int z){
	return y+z;
}
int main(){
	long long int answer = 2;
	int x;
	int y = 1;
	int z = 2;
	while(x<4000000){
		x = fibo(y,z);
		if(x%2 == 0){
			answer+=x;
		}
		y = z;
		z = x;
	}
	cout<<answer<<endl;
}
