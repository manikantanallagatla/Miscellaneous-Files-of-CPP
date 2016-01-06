#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printMajority(int a[],int n){
    map<int,int> hashing;
    for(int i = 0;i<n;i++){
        hashing[a[i]]++;
    }
    map<int,int>::iterator it = hashing.begin();
    while(it!=hashing.end()){
        if(it->second > (n/2)){
            cout<<"Majority Element is ";
            cout<<it->first<<endl;
            return;
        }
        it++;
    }
    cout<<"No Majority Element"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a[] = {1, 3, 3, 3, 2};
    printMajority(a, 5);
    return 0;
}
