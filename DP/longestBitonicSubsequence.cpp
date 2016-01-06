#include<bits/stdc++.h>
#include<math.h>
#define ll int
using namespace std;
ll max(ll a,ll b){
    if(a>b){
        return a;
    }else{
    return b;
    }
}
ll min(ll a,ll b){
    if(a<b){
        return a;
    }else{
    return b;
    }
}

ll *getLis(ll *array,ll n){
    ll *lis = new ll[n];
    fill(lis,lis+n,1);
    for(ll i = 1;i<n;i++){
        for(ll j = 0;j<i;j++){
            if(array[j]<array[i]){
                lis[i] = max(1,(1+lis[j]));
            }
        }
    }
    return lis;
}

ll *getLds(ll *array,ll n){
    ll *lds = new ll[n];
    fill(lds,lds+n,1);
    for(ll i = n-2; i >= 0; i--){
        for(ll j = n-1; j > i; j--){
            if(array[i]>array[j]){
                lds[i] = max(1,(1+lds[j]));
            }
        }
    }

    return lds;
}
int lbs( int arr[], int n ){
    ll *lis = getLis(arr,n);
    ll *lds = getLds(arr,n);
    ll maximum = 0;
    for(ll i = 0;i<n;i++){
        if(maximum<lis[i]+lds[i]){
            maximum = lis[i]+lds[i];
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
int arr[] = {12, 11, 40, 5, 3, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n )-1 );
    return 0;
}
