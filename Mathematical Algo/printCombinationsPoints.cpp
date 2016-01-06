#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define arr_size 100
#define max_point 3
using namespace std;
void printArray(int arr[], int arrsize)
{
  int i;
  for (i = 0; i < arrsize; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
int arr[arr_size];
void printCompositions(int n,int i){
    if(n == 0){
        printArray(arr,i);
    }else{
        if(n<0){
            return;
        }
        for(int k = 1;k<=max_point;k++){
            arr[i] = k;
            printCompositions(n-k,i+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 5;
    printf("Differnt compositions formed by 1, 2 and 3 of %d are\n", n);
    printCompositions(n, 0);
    return 0;
}

