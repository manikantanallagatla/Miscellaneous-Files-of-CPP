#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define n 4
using namespace std;
bool isValid(int x,int y){
    if(x>=0 and x<n and y>=0 and y<n){
        return 1;
    }
    return 0;
}
void search(int mat[n][n],int val){
    int x = 0;
    int y = n-1;
    while(isValid(x,y) == 1){
        if(mat[x][y] == val){
            cout<<"Yaah found at "<<x<<" "<<y<<endl;
            return;
        }
        if(mat[x][y]<val){
            x++;
        }else{
            y--;
        }
    }
    cout<<"Ohh not found"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
    search(mat, 29);
    return 0;
}

