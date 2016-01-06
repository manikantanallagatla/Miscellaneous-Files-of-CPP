#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void findSubArray(int arr[],int size){
    int numberZero = 0;
    int numberOne = 0;
    for(int i = 0;i<size;i++){
        if(arr[i] == 0){
            numberZero++;
        }else{
            numberOne++;
        }
    }
    //cout<<"zeroes: "<<numberZero<<" "<<"Ones: "<<numberOne<<endl;
    int totalSize;
    if(numberZero<=numberOne){
        totalSize = 2*numberZero;
    }else{
        totalSize = 2*numberOne;
    }bool foundArray = 0;
    if(totalSize == 0){
        cout<<"No such Subarray exists vedhu fan!"<<endl;
        foundArray =1;
    }
    //cout<<"Total size: "<<totalSize<<endl;

    numberZero = 0;
    numberOne = 0;
    for(int i = 0;i<(totalSize);i++){
        if(arr[i] == 0){
            numberZero++;
        }else{
            numberOne++;
        }
    }
    //cout<<"zeroes: "<<numberZero<<" "<<"Ones: "<<numberOne<<endl;
    if(numberOne == numberZero and foundArray ==0){
        cout<<0<<" "<<totalSize-1<<endl;
        foundArray = 1;
    }

    for(int i = 1;i<=(size-totalSize) and (foundArray == 0);i++){
        if(arr[i-1] == 0){
            numberZero--;
        }else{
            numberOne--;
        }
        if(arr[i+totalSize-1] == 0){
            numberZero++;
        }else{
            numberOne++;
        }
        if(numberOne == numberZero){
            foundArray =1;
            cout<<i<<" "<<i+totalSize-1<<endl;
        }
    }
    if(foundArray == 0){
        cout<<"No such Subarray present Vedhu fan!"<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] =  {1, 0, 0, 1, 0, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    findSubArray(arr, size);

    return 0;
}
