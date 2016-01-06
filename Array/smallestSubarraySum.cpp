#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int smallestSubWithSum(int arr[],int n,int x){
    int l  = 0;
    int r = 0;
    int minimumSize = INT_MAX;
    int knownLeft = 0;
    int knownRight = 0;
    int knownSum = arr[0];
    int currentSum = arr[0];
    while(r<n){
        if(l == knownLeft and r == knownRight){
            currentSum = knownSum;
        }else{
            if(l>knownLeft){
                knownSum-=arr[knownLeft];
                knownLeft++;
                currentSum = knownSum;
            }else{
                knownRight++;
                knownSum+=arr[knownRight];
                currentSum = knownSum;
            }
        }
        //cout<<currentSum<<" ";
        if(currentSum>x){
            int size = r-l+1;
            if(size<=minimumSize){
                minimumSize = size;
            }
            l++;
        }else{
            r++;
        }
    }

    return minimumSize;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << smallestSubWithSum(arr1, n1, x) << endl;

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    cout << smallestSubWithSum(arr2, n2, x) << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    cout << smallestSubWithSum(arr3, n3, x) << endl;

    return 0;
}

