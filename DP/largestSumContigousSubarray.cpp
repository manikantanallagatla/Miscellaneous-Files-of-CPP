#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int maxSubArraySum(int a[], int size){
    int n = size;
    int max_so_far(0),max_ending_here(0);
    for(int i = 0;i<n;i++){
        max_so_far+=a[i];
        if(max_so_far<0){
            max_so_far = 0;
        }
        if(max_ending_here<max_so_far){
            max_ending_here=max_so_far;
        }
    }
    return max_ending_here;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
