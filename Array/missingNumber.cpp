#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int getMissingNo(int a[],int n){
    int sum = 0;
    int ans = 0;
    for(int i = 1;i<=n+1;i++){
        sum = sum^i;
        //ans = ans^a[i-1];
    }
    for(int i = 1;i<=n;i++){
        //sum = sum^i;
        ans = ans^a[i-1];
    }
    return sum^ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[] = {1,2,4,5,6};
    int miss = getMissingNo(a,5);
    printf("%d", miss);
    return 0;
}
