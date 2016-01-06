#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isDuplet(int arr[],int sum,int l,int r){
    if(l>=r){
        return 0;
    }
    if(arr[l]+arr[r] == sum){
        return 1;
    }
    if(sum<arr[l]+arr[r]){
        return isDuplet(arr,sum,l,r-1);
    }
    return isDuplet(arr,sum,l+1,r);
}
bool isFound(int arr[],int n){
    int l = 0;
    int m = l+1;
    int r = n-1;
    while(l!=(n-3)){
        int x = -1*(arr[l]);
        bool dummy = isDuplet(arr,x,l+1,n-1);
        if(dummy ==1){
            return 1;
        }
        l++;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {-14,-1,0,5,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isFound(arr,n)){
        cout<<"YES FOUND!"<<endl;
    }else{
        cout<<"NO NOT FOUND!"<<endl;
    }
    return 0;
}
