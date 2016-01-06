#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of sorted array:";
	for(int i=0;i<n;i++)
	cin>>a[i];
	int NoOfNonduplicates(1);
	int dummy = a[0];
	for(int i=1;i<n;i++){
		if((a[i])!= dummy){
			dummy = a[i];
			int temp = a[i];
			a[i] = a[NoOfNonduplicates];
			a[NoOfNonduplicates] = temp;
			NoOfNonduplicates++;
		}
	}
	 cout<<'{';
for(int i=0;i<NoOfNonduplicates;i++){
	cout<<a[i]<<',';
	}	
	 cout<<"\b"<<'}';
	return 0;
}

