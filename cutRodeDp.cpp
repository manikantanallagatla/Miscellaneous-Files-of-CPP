#include<iostream>
using namespace std;
int cutRod(int prices[],int size){
	int val[size+1];
	val[0] = 0;
	int i,j;
	for( i = 1;i<=size;i++){
		int max_value = -1;
		for(j = 0;j<i;j++){
			max_value = max(max_value,(val[i-j-1]+prices[j]));
		}
		val[i] = max_value;
	}
	return val[size];
}
int main(){
	int prices [] =  {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(prices)/sizeof(prices[0]);
	cout<<"Maximum value that can be obtained is: "<<cutRod(prices,size);
	return 0;
}
