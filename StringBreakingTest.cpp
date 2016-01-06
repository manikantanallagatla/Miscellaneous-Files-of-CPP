#include<iostream>
using namespace std;
int main(){
	char * str = "IIT ROORKEE";
	for(int i=0;i<11;i++){
			cout<<str<<"\t";
			cout<<&str+i<<"\t";
			cout<<*(str+i)<<"\n";
		}
		//cout<<strlen(str);
}
