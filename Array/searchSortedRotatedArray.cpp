#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int getPivot(int arr1[],int n){
    for(int i = 0;i<n-1;i++){
        if(arr1[i]>arr1[i+1]){
            return i;
        }
    }
    return -1;
}
int pivotedBinarySearch(int arr1[],int n,int key){
    int pivot = getPivot(arr1,n);
    if(key>arr1[pivot] or key<arr1[pivot+1]){
        return 0;
    }
    if(key>=arr1[0]){
        cout<<"present in first subarray"<<endl;
        int l = 0;
        int r = pivot;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr1[mid] == key){
                return mid;
            }
            if(arr1[mid]>key){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }else{
        cout<<"present in second subarray"<<endl;
        int l = pivot+1;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr1[mid] == key){
                return mid;
            }
            if(arr1[mid]>key){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 10;
   printf("Index: %d\n", pivotedBinarySearch(arr1, n, key));

    return 0;
}

