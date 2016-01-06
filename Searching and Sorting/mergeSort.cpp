#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i = 0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = arr[m+i+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 and j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0, n-1);
    print(arr, n);
    return 0;
}
