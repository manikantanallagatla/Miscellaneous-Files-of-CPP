#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int binarysearch(int arr[],int n,int x,int l,int r){
    if(l>r){
        return -1;
    }
    int mid = (l+r)/2;
    if(arr[mid] == x){
        return mid;
    }
    if(arr[mid]<x){
        return binarysearch(arr,n,x,mid+1,r);
    }
    return binarysearch(arr,n,x,l,mid-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1,2,15,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=  15;
    sort(arr,arr+n);
    int result = binarysearch(arr,n,x,0,n-1);
    if(result == -1){
        cout<<"Element not found!"<<endl;
    }else{
        cout<<"Element found at "<<result<<" index."<<endl;
    }
    return 0;
}
