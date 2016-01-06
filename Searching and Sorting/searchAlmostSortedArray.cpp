#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int binarySearch(int arr[],int l,int r,int x){
    if(l>r){
        return -1;
    }
    int mid = (l+r)/2;
    if(arr[mid] == x){
        return mid;
    }
    if(mid<r){
        if(arr[mid+1] == x){
            return mid+1;
        }
    }
    if(mid>l){
        if(arr[mid-1] == x){
            return mid-1;
        }
    }
    if(arr[mid]<x){
        return binarySearch(arr,mid+1,r,x);
    }else{
        return binarySearch(arr,l,mid-1,x);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {3, 2, 10, 4, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 40;
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
    return 0;
}
