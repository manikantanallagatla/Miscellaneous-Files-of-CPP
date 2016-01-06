#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int isPalindrome(int z){
	stringstream ss;
	ss<<z;
	string s = ss.str();
	for(int i = 0;i<s.length()/2;i++){
		if(s[i] != s[s.length()-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int answer = 0;
	int max = 0;
	for(int i = 100;i<1000;i++){
		for(int j = 100;j<1000;j++){
			long z = i*j;
			if(isPalindrome(z) == 1){
				if(z>max){
					max = z;
				}
			}
		}
	}
	cout<<max<<endl;
}
