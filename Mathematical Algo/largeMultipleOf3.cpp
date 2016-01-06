#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void print(vector<int> Mod1,vector<int> Mod0,vector<int> Mod2){
    int index0 = 0;
    int index1 = 0;
    int index2 = 0;
    while(index0<Mod0.size() and index1<Mod1.size() and index2<Mod2.size()){
        if(Mod0[index0]>=Mod1[index1] and Mod0[index0]>=Mod2[index2]){
            cout<<Mod0[index0]<<" ";
            index0++;
        }
        if(Mod0[index0]<=Mod1[index1] and Mod1[index1]>=Mod2[index2]){
            cout<<Mod1[index1]<<" ";
            index1++;
        }
        if(Mod2[index2]>=Mod1[index1] and Mod0[index0]<=Mod2[index2]){
            cout<<Mod2[index2]<<" ";
            index2++;
        }
    }
    if(index0 == Mod0.size()){
        while(index1<Mod1.size() and index2<Mod2.size()){
        if(Mod1[index1]>=Mod2[index2]){
            cout<<Mod1[index1]<<" ";
            index1++;
        }
        if(Mod2[index2]>=Mod1[index1]){
            cout<<Mod2[index2]<<" ";
            index2++;
        }
    }
    while(index1<Mod1.size()){
            cout<<Mod1[index1]<<" ";
            index1++;
    }
    while(index2<Mod2.size()){
            cout<<Mod2[index2]<<" ";
            index2++;
    }
    }
    if(index1 == Mod1.size()){
        while(index0<Mod0.size() and index2<Mod2.size()){
        if(Mod0[index0]>=Mod2[index2]){
            cout<<Mod0[index0]<<" ";
            index0++;
        }
        if(Mod2[index2]>=Mod0[index0]){
            cout<<Mod0[index0]<<" ";
            index0++;
        }
    }
    while(index0<Mod0.size()){
            cout<<Mod0[index0]<<" ";
            index0++;
    }
    while(index2<Mod2.size()){
            cout<<Mod2[index2]<<" ";
            index2++;
    }
    }
    if(index2 == Mod2.size()){
        while(index1<Mod1.size() and index0<Mod0.size()){
        if(Mod1[index1]>=Mod0[index0]){
            cout<<Mod1[index1]<<" ";
            index1++;
        }
        if(Mod0[index0]>=Mod1[index1]){
            cout<<Mod0[index0]<<" ";
            index0++;
        }
    }
    while(index1<Mod1.size()){
            cout<<Mod1[index1]<<" ";
            index1++;
    }
    while(index0<Mod0.size()){
            cout<<Mod0[index0]<<" ";
            index0++;
    }
    }
}
bool findMaxMultupleOf3(int arr[],int size){
    vector<int>Mod1;
    vector<int>Mod0;
    vector<int>Mod2;
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum+=arr[i];
        if(arr[i]%3 == 0){
            Mod0.push_back(arr[i]);
        }
        if(arr[i]%3 == 1){
            Mod1.push_back(arr[i]);
        }
        if(arr[i]%3 == 2){
            Mod2.push_back(arr[i]);
        }
    }
    sort(Mod0.begin(),Mod0.end());
    sort(Mod1.begin(),Mod1.end());
    sort(Mod2.begin(),Mod2.end());
    reverse(Mod0.begin(),Mod0.end());
    reverse(Mod1.begin(),Mod1.end());
    reverse(Mod2.begin(),Mod2.end());
    if(sum%3 == 0){
        print(Mod0,Mod1,Mod2);
    }
    if(sum%3 == 1){
        Mod1.pop_back();
        print(Mod0,Mod1,Mod2);
    }
    if(sum%3 ==2){
        Mod2.pop_back();
        print(Mod0,Mod1,Mod2);
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {8, 1, 7, 6, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    if (findMaxMultupleOf3( arr, size ) == 0)
        printf( "Not Possible" );
    return 0;
}
