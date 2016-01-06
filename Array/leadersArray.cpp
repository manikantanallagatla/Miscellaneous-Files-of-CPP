#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printLeaders(int arr[],int n){
    vector<int> result;
    int maximum = arr[n-1];
    result.push_back(maximum);
    for(int i = n-2;i>=0;i--){
        if(maximum<arr[i]){
            maximum = arr[i];
            result.push_back(maximum);
        }
    }
    for(int i = result.size()-1;i>=0;i--){
        cout<<result[i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}
