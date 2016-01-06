#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define R 3
#define C 3
using namespace std;
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};
int dp[R][C];
bool isValid(int i,int j){
    if(i<R and i>=0 and j<C and j>=0){
        return true;
    }
    return false;
}
bool isAdjacent(char prev,char curr){
    if(curr - prev == 1){
        return 1;
    }
    return 0;
}
int getLenUtil(char mat[R][C], int i,int j,char prev){
    if(isValid(i,j) == false or isAdjacent(prev,mat[i][j]) == false){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 0;
    for(int k = 0; k<8;k++){
        ans = max(ans,(1+getLenUtil(mat,i+x[k],j+y[k],mat[i][j])));
    }
    dp[i][j] = ans;
    return ans;
}
int getLen(char mat[R][C],char s){
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            if(mat[i][j] == s){
                for(int k = 0;k<8;k++){
                    ans = max(ans,1+getLenUtil(mat,i+x[k],j+y[k],mat[i][j]));
                }
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    char mat[R][C] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};

    cout << getLen(mat, 'a') << endl;
    cout << getLen(mat, 'e') << endl;
    cout << getLen(mat, 'b') << endl;
    cout << getLen(mat, 'f') << endl;
    return 0;
}
