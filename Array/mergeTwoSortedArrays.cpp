#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int * merge(int array1[],int array2[],int m,int n){
    int * result = new int[m+n];
    int resultIndex = 0;
    int index1 = 0;
    int index2 = 0;
    while(index1<m and index2<n){
        if(array1[index1]<=array2[index2]){
            result[resultIndex] = array1[index1];
            index1++;
            resultIndex++;
        }else{
            result[resultIndex] = array2[index2];
            resultIndex++;
            index2++;
        }
    }
    while(index1<m){
            result[resultIndex] = array1[index1];
            index1++;
            resultIndex++;
    }
    while(index2<n){
            result[resultIndex] = array2[index2];
            resultIndex++;
            index2++;
    }
    return result;

}
void printArray(int array[],int n){
    cout<<"This is the array: \n";
    for(int i = 0;i<n;i++){
        cout<<array[i]<<" ";
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int M[] = {2, 8, 13, 15, 20};
    int N[] = {5, 7, 9, 25};
    int n = sizeof(N)/sizeof(N[0]);
    int m = sizeof(M)/sizeof(M[0]);

  /*Merge N[] into mPlusN[] */
    int * array = merge(M, N, m, n);

  /* Print the resultant mPlusN */
    printArray(array, m+n);
    return 0;
}

