#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter size of Array ";
	cin>>n;
	int a[n];
	cout<<"Enter values of array:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Given array is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	for(int i=0;i<n-1;i++){
		if(i%2==0){
			if(a[i]>a[i+1]){
			int temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			}
		}
		 else{
		 	if(a[i]<a[i+1]){
		 		int temp = a[i];
		 		a[i] = a[i+1];
		 		a[i+1] = temp;
		 	}
		 }
	}
	cout<<"\n";
	cout<<"Wiggly permutation of given array is:"<<endl;
		for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}
