#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void minAbsSumPair(int arr[],int n){
    sort(arr,arr+n);
    int l = 0;
    int r = n-1;
    int min_l;
    int min_r;
    int minimum = INT_MAX;
    while(l<r){
        int dummy = abs(arr[l]+arr[r]);
        if(dummy <minimum){
            minimum = dummy;
            min_l = l;
            min_r = r;
            }else{
            if(dummy<0){
                l++;
            }else{
                r--;
            }
        }
    }
    cout<<arr[min_l]<<" "<<arr[min_r]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 60, -10, 70, -80, 85};
    minAbsSumPair(arr, 6);
    return 0;
}



