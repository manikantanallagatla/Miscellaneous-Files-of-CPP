#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
// Structure for a pair
struct chain
{
  int a;
  int b;
};
bool myfunc(chain x,chain y){
    if(x.a<y.a){
        return 1;
    }
    return 0;
}
int maxChainLength(chain arr[],int n){
    sort(arr,arr+n,myfunc);
    for(int i = 0;i<n;i++){
        cout<<arr[i].a<< " "<<arr[i].b<<endl;
    }
    int dp[n];
    fill(dp,dp+n,1);
    for(int i = 1;i<n;i++){
            int maximum = INT_MIN;
        for(int j = 0;j<i;j++){
            if(arr[j].b<arr[i].a){
                if(dp[j]>=maximum){
                    maximum = dp[j];
                }
            }
        }
        if(maximum!=INT_MIN)
            dp[i] = maximum+1;
    }
    for(int i = 0;i<n;i++){
        cout<<dp[i]<< " ";
    }cout<<endl;
    int maximum = INT_MIN;
    for(int i = 0;i<n;i++){
        if(maximum<=dp[i]){
            maximum = dp[i];
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct chain arr[] = { {5, 24}, {27, 40},{15, 25}
                          , {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           maxChainLength( arr, n ));

    return 0;
}

