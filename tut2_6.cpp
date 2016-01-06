#include<iostream>
using namespace std;
bool present(int n){
	bool present = false;
	int quo,rem;
	while(n>0){
		rem = n%10;
		if(rem == 5){
			present = true;
			return present;
		}
		n = n/10;
	}
	return present;
}
int NoOfNumbers(int k){
	int Numbers(0);
	for(int i=1;i<k;i++){
		if(present(i) == false)
		  Numbers++;
}
return Numbers;
}
int main(){
	int count;
	int * num = NULL;
	int n;
	cout<<"Enter a number for which u want to perform given operation:";
	cin>>n;
	count = NoOfNumbers(n);
	cout<<"Count is "<<count<<endl;
    num = new int[count];
    int k=0;
    for(int i=1;i<n;i++){
		if(present(i) == false){
			num[k] = i;
			k++;
			cout<<i<<endl;}
	}
	return 0;
}
