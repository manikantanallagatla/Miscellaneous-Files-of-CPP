#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isPalindrome(char *str){
    ll n = strlen(str);
    //bool result = true;
    for(ll i = 0;i<(n/2);i++){
        if(str[i] == str[n-i-1]){
            return false;
        }
    }
    return true;
}
int minPalPartion(char *str){
    int n = strlen(str);
    if(n ==1){
        return 0;
    }
    if(isPalindrome(str) == true){
        return 0;
    }
    ll ans[n][n];
    bool P[n][n];
    for(ll i = 0;i<n;i++){
        ans[i][i] = 0;
        P[i][i] = true;
    }
     for (ll L=2; L<=n; L++)
    {
        // For substring of length L, set different possible starting indexes
        for (ll i=0; i<n-L+1; i++)
        {
            ll j = i+L-1; // Set ending index

            // If L is 2, then we just need to compare two characters. Else
            // need to check two corner characters and value of P[i+1][j-1]
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];

            // IF str[i..j] is palindrome, then C[i][j] is 0
            if (P[i][j] == true)
                ans[i][j] = 0;
            else
            {
                // Make a cut at every possible localtion starting from i to j,
                // and get the minimum cost cut.
                ans[i][j] = INT_MAX;
                for (ll k=i; k<=j-1; k++){
                    ans[i][j] = min (ans[i][j], ans[i][k] + ans[k+1][j]+1);
            }
            }
        }
    }
    return ans[0][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    char str[] = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d",minPalPartion(str));
    return 0;
}
