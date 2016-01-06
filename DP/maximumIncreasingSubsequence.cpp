#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
ll max(ll a,ll b){
    if(a>b){
        return a;
    }else{
    return b;
    }
}
ll getLis(ll *array,ll n){
    ll lis[n];
    for(ll i = 0;i<n;i++){
        lis[i] = array[i];
    }
    for(ll i = 1;i<n;i++){
        for(ll j = 0;j<i;j++){
            if(array[j]<array[i]){
                lis[i] = max(lis[i],(array[i]+lis[j]));
            }
        }
    }
    ll maximum = 0;
    for(ll i = 0;i<n;i++){
        if(maximum<lis[i]){
            maximum = lis[i];
        }
    }
    return maximum;
}

int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cout<<"Enter the size of n:"<<endl;
    cin>>n;
    ll array[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(ll i = 0;i<n;i++){
        cin>>array[i];
    }
    cout<<"array is ";
    for(ll i = 0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"maxSumLIS is "<<getLis(array,n)<<endl;

    return 0;
}
