#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int cutRod(int price[], int n){
    if(n<=0){
        return 0;
    }else{
        ll val[n+1];
        val[0] = 0;
        for(ll i = 1;i<n+1;i++){
            ll maximum = INT_MIN;
            for(ll j = 0;j<i;j++){
                ll x = price[j]+val[i-j-1];
                if(x>maximum){
                    maximum = x;
                }
            }
            val[i] = maximum;
        }
        return val[n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    return 0;
}
