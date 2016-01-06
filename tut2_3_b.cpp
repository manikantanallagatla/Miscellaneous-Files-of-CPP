#include<iostream>
using namespace std;
void sort(int a[],int size){
	int noOfZeros = 0;
	for(int i=0;i<size;i++)
	if(a[i]==0)
		noOfZeros++;
	for(int i=0;i<size;i++){
		if(noOfZeros != 0){
			a[i] = 0;
			noOfZeros--;
		}
		else
			a[i] = 1;
	}
}
int main(){
	int n;
	cout<<"Enter value of n:"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter Array elements as 0 or 1:"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Given values are:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
	sort(a,n);
	cout<<"After sorting values are:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
