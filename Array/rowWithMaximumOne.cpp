#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define R 4
#define C 4
using namespace std;
int rowWithMax1s(bool mat[R][C]){
    int ans;
    int row;
    for(int i = 0;i<C;i++){
        if(mat[0][i] == 1){
                row = 0;
            ans = i;
            break;
        }
    }
    //cout<<"row: "<<row<<" ans: "<<ans<<endl;
    for(int i = 1;i<R;i++){
        if(mat[i][ans] == 0){
            continue;
        }
        for(int j = ans-1;j>=0;j--){
            if(mat[i][j] == 1){
                ans = j;
                row = i;
            }else{
                break;
            }
        }
    }
    return row;
}
int main(){
    ios_base::sync_with_stdio(false);
    bool mat[R][C] = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    printf("Index of row with maximum 1s is %d \n", rowWithMax1s(mat));

    return 0;
}

