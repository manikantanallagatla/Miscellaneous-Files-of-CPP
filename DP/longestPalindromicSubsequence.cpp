#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int longestPalSubstr( char *str ){
    int n = strlen(str);
    bool pal[n][n];
    for(int i = 0;i<n;i++){
        pal[i][i] = 1;
    }
    for(int i = 0;i<n-1;i++){
        if(str[i] == str[i+1]){
            pal[i][i+1] = 1;
        }
    }
    for(int k = 3;k<=n;k++){
        for(int i = 0;i<(n-k+1);i++){
                int j = i+k-1;

                pal[i][j] = pal[i+1][j-1] && (str[i] == str[j]);

        }
    }
    int maximum = 1;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int x = j-i+1;
            if(pal[i][j] == 1){
                if(x>maximum){
                    maximum = x;
    //                cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longestPalSubstr( str ) );
    return 0;
}
