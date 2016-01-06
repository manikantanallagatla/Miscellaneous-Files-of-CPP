#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printCeilFloor(int arr[],int n,int x){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == x){
            l = r = mid;
            break;
        }
        if(arr[mid]<x){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(l<n){
        cout<<"The ceil of the given element "<<x<<" is "<<arr[l]<<endl;
    }else{
        cout<<"The ceil does not exist!"<<endl;
    }

    if((r)>=0){
        cout<<"The floor of the given element "<<x<<" is "<<arr[r]<<endl;
    }else{
        cout<<"The floor does not exist!"<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
   int arr[] = {1, 2, 8, 10, 10, 12, 19};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x ;
   cout<<"Enter the Key:"<<endl;
    cin>>x;
   printCeilFloor(arr,n,x);

    return 0;
}

