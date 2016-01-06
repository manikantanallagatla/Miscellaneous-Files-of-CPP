#include<bits/stdc++.h>
#include<math.h>
#define array txt
#define ll long long int
using namespace std;
void checkPalindromes(string txt){
    int size = txt.length();
    int n = size;
    bool palindrome[size][size];
    for(int i =0 ;i<size;i++){
        palindrome[i][i] = 1;
    }
    for(int k = 1;k<n;k++){
        for(int i = 0;i<n-k;i++){
            int j =  i+k;
            if(i == j-1){
                if(array[i] == array[j]){
                    palindrome[i][j] = 1;
                }else{
                    palindrome[i][j] = 0;
                }
            }else{
            if(palindrome[i+1][j-1] ==1){
                if(array[i] == array[j]){
                    palindrome[i][j] = 1;
                }else{
                    palindrome[i][j] = 0;
                }
            }else{
                palindrome[i][j] = 0;
            }
        }}
    }
    for(int i = 0;i<n;i++){
        cout<<palindrome[0][i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    string txt = "aabaacaabaa";
    checkPalindromes(txt);

    return 0;
}

