#include<iostream>
using namespace std;
void dummyFunction(int arr[],int size,int r,int dummy[],int start,int end,int index){
	if(index==r){
		for(int j=0;j<r;j++){
			cout<<dummy[j]<<"\t";
			}
		cout<<endl;
		return;
	}
	for(int i=start;i<=end;i++){
		dummy[index] = arr[i];
		dummyFunction(arr,size,r,dummy,i+1,end,index+1);
	}
}
void printAllPermutations(int arr[],int size,int r){
	int dummy[r];
	dummyFunction(arr,size,r,dummy,0,size-1,0);
}
int main(){
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int r;
	cout<<"Enter the value of r:";
	cin>>r;
	printAllPermutations(a,n,r);
}
