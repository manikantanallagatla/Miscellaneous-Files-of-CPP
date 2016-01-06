#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printNGE(int arr[],int n){
    int i = 0;
    stack<int> s;
    s.push(arr[0]);
    for(i = 1;i<n;i++){
        int next = arr[i];
        if(s.empty() == 0){
            int element = s.top();
            s.pop();
            while(element<next){
                cout<<next<<endl;
                if(s.empty() ==1){
                    break;
                }
                element = s.top();
                s.pop();
            }
            if(element >next){
                s.push(next);
            }
        }
        s.push(next);
    }
    while(s.empty() == 0){
        int element = s.top();
        int next =-1;
        cout<<next<<endl;
        s.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[] = {11,13,21,3};
    int n = sizeof(arr)/sizeof(int);
    printNGE(arr,n);
    return 0;
}
