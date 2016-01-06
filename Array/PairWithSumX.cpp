#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool hasElements(int a[],int n,int sum){
    map<int,int> hashing;
    for(int i = 0;i<n;i++){
        hashing[a[i]]++;
    }
    for(int i = 0;i<n;i++){
        int dummy = sum-a[i];
        hashing[a[i]]--;
        if(hashing[dummy]!=0){
            return 1;
        }
        hashing[a[i]]++;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[] = {1,5,4,6,10,-18,45};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 2;
    if(hasElements(a,n,sum)){
        cout<<"Yaa found!"<<endl;
    }else{
        cout<<"Oh Not Found!"<<endl;
    }
    return 0;
}
