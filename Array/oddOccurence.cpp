#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int getOddOccurrence(int ar[],int n){
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = ans ^ (ar[i]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOddOccurrence(ar, n));

    return 0;
}

