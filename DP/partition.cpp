#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isPartition(int arr[],int n,int sum){
    bool ans[sum+1][n+1];
    for(ll i = 0;i<n+1;i++){
        ans[0][i] = true;
    }
    for(ll i = 1;i<sum+1;i++){
        ans[i][0] = false;
    }
    for(ll i = 1;i<sum+1;i++){
        for(ll j = 1;j<n+1;j++){
            ans[i][j] = ans[i][j-1];
            if(i-arr[j-1]>=0){
                ans[i][j] = ans[i][j] or ans[i-arr[j-1]][j-1];
            }
        }
    }
    return ans[sum][n];
}
bool findPartiion (int arr[], int n){
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2 == 1){
        return false;
    }
    sum/=2;
    return isPartition(arr,n,sum);
}
int main(){
    ios_base::sync_with_stdio(false);
int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
     printf("Can be divided into two subsets "
            "of equal sum");
  else
     printf("Can not be divided into two subsets"
            " of equal sum");
    return 0;
}
