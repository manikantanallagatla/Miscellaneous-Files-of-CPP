#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
ll fibb[100];

ll getFibb(ll n){
    if(n == 0){
        return 1;
    }
    if(n<1){
        return 0;
    }else{
        if(fibb[n]!=0){
            return fibb[n];
        }
        else{
            fibb[n] = getFibb(n-1)+getFibb(n-2);
            return fibb[n];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    fill(fibb,fibb+100,0);
    cout<<"Enter the number:"<<endl;
    ll temp;

    cin>>temp;
    temp--;
    cout<<getFibb(temp)<<endl;
    return 0;
}
