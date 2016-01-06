#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x = n*(n+1)*(2*n+1)/6;
	int y = (((n*(n+1))/2));
	y = y*y;
	cout<<abs(x-y)<<endl;
}
