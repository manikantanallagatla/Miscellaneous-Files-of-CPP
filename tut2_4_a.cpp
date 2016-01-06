#include<iostream>
using namespace std;
template<class T>
void reverse(T a[],int size){
	if(size%2==0){
	for(int i=0;i<size/2;i++){
		T temp = a[((size-1)-i)];
		a[((size-1)-i)] = a[i];
		a[i] = temp;
	}
}
	else{
		for(int i=0;i<(size/2)+1;i++){
		T temp = a[((size-1)-i)];
		a[((size-1)-i)] = a[i];
		a[i] = temp;
	}
}
}
int main(){
	int n;
	cout<<"Enter size of Array:";
	cin>>n;
	int a[n];
	cout<<"Enter elements of Array:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Array elements are:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
	reverse(a,n);
	cout<<"After reversing"<<endl;
	cout<<"Array elements are:";		
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
