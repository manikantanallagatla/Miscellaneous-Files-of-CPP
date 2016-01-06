#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printUnsorted(int arr[],int n){
    int dummy[n];
    for(int i = 0;i<n;i++){
        dummy[i] = arr[i];
    }
    sort(dummy,dummy+n);
    int l,r;
    for(int i = 0;i<n;i++){
        if(dummy[i]!=arr[i]){
            l = i;
            break;
        }
    }
    for(int i = n-1;i>=0;i--){
        if(dummy[i]!=arr[i]){
            r = i;
            break;
        }
    }
    cout<<l<<" "<<r<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printUnsorted(arr, arr_size);

    return 0;
}

