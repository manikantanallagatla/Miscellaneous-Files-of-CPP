#include<bits/stdc++.h>
#include<math.h>
#define m 4
#define n 4
#define ll long long int
using namespace std;
void printSpiral(int mat[m][n],int startx,int starty,int hor,int ver,int count){
    if(hor <= 0 and ver <= 0){
        return;
    }
    if(count == 0){
        return;
    }
    if(hor>0 and count>0){
    for(int i = startx;i<startx+hor;i++){
        cout<<mat[startx][i]<<" ";
        count--;
    }}
    if(ver>0 and count>0){
    for(int i = starty+1;i<starty+ver;i++){
        cout<<mat[i][startx+hor-1]<<" ";count--;
    }}
    if(hor>0 and count>0){
    for(int i = startx+hor-2;i>=startx;i--){
        cout<<mat[starty+ver-1][i]<<" ";count--;
    }}
    if(ver>0 and count>0){
    for(int i = starty+ver-2;i>starty;i--){
        cout<<mat[i][startx]<<" ";count--;
    }}
    printSpiral(mat,startx+1,starty+1,hor-2,ver-2,count);
}
int main(){
    ios_base::sync_with_stdio(false);
    int mat[m][n] = { {1, 2, 3, 4,},
                        {5,6,7,8 },
                    {9, 10,11,12},
                    {13, 14, 15, 16}
                  };
    printSpiral(mat,0,0,n,m,n*m);

    return 0;
}

