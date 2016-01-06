#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct pair1{
    int a;
    int b;
};
bool func_name(struct pair1 x,struct pair1 y){
    if(x.a<y.a){
        return 1;
    }
    return 0;
}
void sorted(struct pair1 arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[j].a>arr[j+1].a){
                int temp1 = arr[j].a;
                int temp2 = arr[j].b;
                arr[j].a = arr[j+1].a;
                arr[j].b = arr[j+1].b;
                arr[j+1].a = temp1;
                arr[j+1].b = temp2;
            }
        }
    }
    //return arr;
}
int maxChainLength( struct pair1 arr[], int n){
    int mcl[n];
    fill(mcl,mcl+n,1);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j].b<arr[i].a and mcl[i]<mcl[j]+1){
                mcl[i] = mcl[j]+1;
            }
        }
    }
    int maximum = INT_MIN;
    for(int i = 0;i<n;i++){
        if(maximum<mcl[i]){
            maximum = mcl[i];
        }
    }
    return maximum;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct pair1 arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,func_name);
    for(int i = 0;i<n;i++){
        cout<<arr[i].a<<" "<<arr[i].b<<endl;
    }
    printf("Length of maximum size chain is %d\n",
           maxChainLength( arr, n ));
    return 0;
}
