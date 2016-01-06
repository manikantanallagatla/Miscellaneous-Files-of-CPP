#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void swap(int &a,int &b){
    int c = a;
    a = b;
    b = c;
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[min_idx],arr[i]);
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
    selectionSort(arr, n);
    print(arr, n);
    return 0;
}
