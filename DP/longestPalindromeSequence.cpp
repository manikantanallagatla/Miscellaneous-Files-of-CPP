#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int lps(char *seq){
    ll s = strlen(seq);
    ll ans[s][s];
    for(ll i = 0;i<s;i++){
        ans[i][i] = 1;
    }
    for(ll cl = 2;cl<=s;cl++){
        for(ll i=0;i<(s-cl+1);i++){
                ll j = i+cl-1;
            if(seq[i] == seq[j]){
                if(i == j-1){
                    ans[i][j] = 2;
                }
                else
                    ans[i][j] = ans[i+1][j-1]+2;
            }else{
                ans[i][j] = max(ans[i+1][j],ans[i][j-1]);
            }
        }
    }
    return ans[0][s-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq));
    getchar();
    return 0;
}
