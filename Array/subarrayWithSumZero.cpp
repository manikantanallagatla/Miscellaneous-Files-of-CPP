#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool printZeroSumSubarray(int arr[],int n){
    map<int,int> sumArray;
    int sum = arr[0];
    sumArray[sum] = 1;
    for(int i = 1;i<n;i++){
        sum+=arr[i];
        if(sumArray[sum]!=0){
            return 1;
        }else{
            sumArray[sum] =1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {-3, 2, 3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (printZeroSumSubarray(arr,n))
            cout<<"Found a subarray with 0 sum";
        else
            cout<<"No Subarray with 0 sum";

    return 0;
}

