#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isSubsetSum(int set[], int n, int sum){
    bool subset[sum+1][n+1];
    for(int i = 0;i<n+1;i++){
        subset[0][i] = 1;
    }
    for(int i = 1;i<sum+1;i++){
        subset[i][0] = 0;
    }
    for(int i = 1;i<sum+1;i++){
        for(int j = 1;j<n+1;j++){
            subset[i][j] = subset[i][j-1];
            if(i-set[j-1]>=0){
                subset[i][j] = subset[i][j] || (subset[i-set[j-1]][j-1]);
            }
        }
    }
    return subset[sum][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
