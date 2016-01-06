#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void leftRotate(int arr[],int d,int n){
    reverse(arr+0,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr+0,arr+n);
}
void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, d, n);
    printArray(arr, n);
    return 0;
}

