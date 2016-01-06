#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int findoptimal(int N){
    if(N<7){
        return N;
    }
    int screen[N+1];
    for(int i = 1;i<=6;i++){
        screen[i] = i;
    }
    for(int i = 7;i<=N;i++){
        int ans = INT_MIN;
        for(int j = i-3;j>=1;j--){
            int x = screen[j]+screen[j]*(i-j-2);
            if(x>ans){
                ans = x;
            }
        }
        screen[i] = ans;
    }
    return screen[N];
}
int main(){
    ios_base::sync_with_stdio(false);
    int N;

    // for the rest of the array we will rely on the previous
    // entries to compute new ones
    for (N=1; N<=20; N++)
        printf("Maximum Number of A's with %d keystrokes is %d\n",
               N, findoptimal(N));
    return 0;
}
