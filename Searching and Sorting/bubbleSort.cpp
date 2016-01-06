#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void swap(int &a,int &b){
    int c = a;
    a = b;
    b = c;
}
void bubbleSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubbleSort(arr, n);
    print(arr, n);
    return 0;
}
