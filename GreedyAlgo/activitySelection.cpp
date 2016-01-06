#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printMaxActivities(int s[], int f[], int n){
    cout<<0<<" ";
    int lastEnd = f[0];
    for(int i = 1;i<n;i++){
        if(s[i]>=lastEnd){
            cout<<i<<" ";
            lastEnd = f[i];
        }else{

        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
