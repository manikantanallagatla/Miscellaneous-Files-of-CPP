#include<iostream>
using namespace std;
int main(){
int **A;
A= new int*[3];
int a1[] = {1,2,3};
int a2[] = {1,2};
int a3[] = {1};
A[0] = a1;
A[1] = a2;
A[2] = a3;
for(int i=0;i<3;i++){
		cout<<*(*(A)+i)<<endl;
}
}
