#include<iostream>
#include<vector>
using namespace std;
void median(vector<int> array,int n){
	
	int temp = array[n-1];
	int index = (n-2);
	while(temp<array[index] &&(index>=0)){
		array[index] = array[index-1];
		index--;
	}
	if(index>=0 && (temp<array[index]))
	array[index] = temp;
	for(int i =0 ;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"These are the elements! "<<endl;
	if(n%2 == 0){
		cout<<(array[n/2]+array[(n/2)-1])/2<<endl;
	}
	else{
		cout<<(array[(n)/2])<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> array;
	for(int i = 1;i<=n;i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
		median(array,(i));
	}
}
