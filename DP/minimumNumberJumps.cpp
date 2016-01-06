#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int minJumps(int arr[], int n){
    if(n == 0 or arr[0] == 0){
        return INT_MAX;
    }
    int jumps[n];
    jumps[0] = 0;
    for(int i = 1;i<n;i++){
        jumps[i] = INT_MAX;
        for(int j = 0;j<i;j++){
            if(i<=j+arr[j] and jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    return jumps[n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
    return 0;
}
