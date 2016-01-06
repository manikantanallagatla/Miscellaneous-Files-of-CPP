#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	
	vector<char> array;
	for(int i = 0;i<s.length();i++){
		if(s[i]!=' '){
			array.push_back(s[i]);
		}
		else{
			
		}
	}
	char ch[array.size()];
	for(int i =  0;i<array.size();i++){
		cout<<array[i];
	}
	
}
