#include<iostream>
#include<string>
using namespace std;
void permute(string &s,int start,int n){
	if(start >= n){
		return;
	}
	if(n == 1){
		cout<<s[start]<<endl;
		return;
	}
	for(int i = start;i<s.length();i++ ){
		cout<<s[i];
		permute(s,i+1,n-1);
	}
}
int main(){
	string s;
	cin>>s;
	permute(s,0,3);
}
