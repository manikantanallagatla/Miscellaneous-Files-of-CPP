#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void SieveOfEratosthenes(int n){
    bool primes[n+1];
    memset(primes,1,sizeof(primes));
    for(int i = 2;i*i<=n;i++){
        if(primes[i] ==1){
            for(int j = 2;j*i<=n;j++){
                primes[i*j] = 0;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if(primes[i] ==1){
            cout<<i<<" ";
        }
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 100;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
