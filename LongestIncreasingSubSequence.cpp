#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int array[n];
	for(int i = 0;i<n;i++){
		cin>>array[i];
	}
	int lis[n];
	fill(lis,lis+n,1);
	lis[0] = 1;
	for(int i = 1;i<n;i++){
		int max = 0;
		for(int j = 0;j<i;j++){
			if(lis[j]>max && array[j]<array[i]){
				max = lis[j];
			}
		}
		lis[i] = max+1;
	}
	/*for(int i = 0;i<n;i++){
		cout<<lis[i]<<" ";
	}*/
	int max = 0;
	for(int i = 0;i<n;i++){
		if(max<lis[i]){
			max = lis[i]
		}
	}
	cout<<max<<endl;
}
