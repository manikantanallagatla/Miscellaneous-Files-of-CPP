#include<iostream>
using namespace std;
int main(){
	string s;
	int lineNo = 0;
	while(getline(cin,s)){
		cout<<++lineNo<<":"<<s<<endl;
	}
}
