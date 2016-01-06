#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void insertionSort(int arr[],int n){
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1] =  arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
