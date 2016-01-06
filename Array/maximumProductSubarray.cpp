#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int maxSubarrayProduct(int arr[],int n){
    //by observation the subarrays are splitted by zeroes and odd number of negative numbers
    int numberNegatives = 0;
    int maximumProduct = INT_MIN;
    int previousProduct = 1;
    int presentProduct = 1;
    int firstNegative = 1;
    for(int i = 0;i<n;i++){
          if(arr[i]<0){
          numberNegatives++;
          if(numberNegatives == 1){
            firstNegative = presentProduct;
          }
          if(numberNegatives%2 == 1){
          previousProduct = presentProduct;
          }
          presentProduct*=arr[i];
          }
          if(arr[i]>0){
          presentProduct*=arr[i];
          }
          if(arr[i] == 0){
            if(i>0){
                if(numberNegatives%2 == 0){
                    if(presentProduct>=maximumProduct){
                        maximumProduct = presentProduct;
                    }
                    numberNegatives = 0;
                    previousProduct = 1;
                    presentProduct = 1;
                }else{
                    int dummy1 = previousProduct;
                    int dummy2 = presentProduct/(firstNegative);
                    int ans = max(dummy1,dummy2);
                    if(ans>=maximumProduct){
                        maximumProduct = ans;
                    }
                    numberNegatives = 0;
                    previousProduct = 1;
                    presentProduct = 1;
                }
            }
          }
    }
    if(numberNegatives%2 == 0){
                    if(presentProduct>=maximumProduct){
                        maximumProduct = presentProduct;
                    }
                    numberNegatives = 0;
                    previousProduct = 1;
                    presentProduct = 1;
                }else{
                    int dummy1 = previousProduct;
                    int dummy2 = presentProduct/(firstNegative);
                    int ans = max(dummy1,dummy2);
                    if(ans>=maximumProduct){
                        maximumProduct = ans;
                    }
                    numberNegatives = 0;
                    previousProduct = 1;
                    presentProduct = 1;
                }
    return maximumProduct;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d",
            maxSubarrayProduct(arr, n));

    return 0;
}

