#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int FindMaxSum(int arr[],int n){
    int incl[n];
    int excl[n];
    incl[0] = arr[0];
    excl[0] = 0;
    for(int i = 1;i<n;i++){
        incl[i] = excl[i-1]+arr[i];
        excl[i] =  max(incl[i-1],excl[i-1]);
    }
    return max(incl[n-1],excl[n-1]);
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {5, 5, 10, 100, 10, 5};
    printf("%d \n", FindMaxSum(arr, 6));
    return 0;
}
