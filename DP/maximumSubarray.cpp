#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define bool int
#define R 6
#define C 5
using namespace std;
void printMaxSubSquare(bool M[R][C]){
    int S[R][C];
    for(int i = 0;i<R;i++){
        S[i][0] = M[i][0];
    }
    for(int i = 0;i<C;i++){
        S[0][i] = M[0][i];
    }
    for(int i = 1;i<R;i++){
        for(int j = 1;j<C;j++){
            if(M[i][j] == 1){
                S[i][j] = min(S[i-1][j],min(S[i-1][j-1],S[i][j-1]))+1;
            }else{
                S[i][j] = 0;
            }
        }
    }int i,j;
    for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      cout<<S[i][j]<<" ";
    }cout<<endl;
  }
   int max_of_s = S[0][0];int max_i = 0;int max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i;
         max_j = j;
      }
    }
  }
  //cout<<max_i<<" "<<max_j<<endl;

  printf("\n Maximum size sub-matrix is: \n");
  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    bool M[R][C] =  {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 0, 1},
                   {0, 0, 0, 0, 0}};

  printMaxSubSquare(M);
    return 0;
}
