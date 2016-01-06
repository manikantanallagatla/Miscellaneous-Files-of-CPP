#include<iostream>
using namespace std;
void findTwoNumbers(int a[],int size,int sum){
	int found(0);
	int l(0),r(size-1);
	while(l<r){
		if(a[l] + a[r] == sum){
     	found++;
	    cout<<"Found a pair.";
	    break;
			}
		   else{
		       if(a[l] + a[r] <sum)
			   l++;
		           else
			        r--;
	}
}
if(found==0)
	cout<<"NOt Found a pair.";
}
int main(){
	int n;
	cout<<"Enter the size of Array:"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter  values of Array:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int searcher;
	cout<<"Enter the number for which u want 2 numbers"<<endl;
	cout<<" in array whose sum is the given number:";
	cin>>searcher; 
	cout<<"\n";
	cout<<"\n";
	findTwoNumbers(a,n,searcher);
}
