#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
vector<int> answer;
void printAnswer(){
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }cout<<endl;
}
void printCombinationsUtil(int arr[],int i,int n,int r){
    if(i>n){
        return;
    }
    if(answer.size() == r){
        printAnswer();
        //answer.pop_back();
        return;
    }
    answer.push_back(arr[i]);
    printCombinationsUtil(arr,i+1,n,r);
    answer.pop_back();
    printCombinationsUtil(arr,i+1,n,r);
}
void printCombinations(int arr[],int n,int r){
    if(r<=0){
        return;
    }
    printCombinationsUtil(arr,0,n,r);
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombinations(arr,n, r);

    return 0;
}

