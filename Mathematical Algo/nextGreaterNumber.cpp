#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void swap(char &x,char &y){
    char temp = x;
    x = y;
    y = temp;
}
void findNext(char digits[],int n){
    int i;
    for(i = n-1;i>=1;i--){
        if(digits[i-1]<digits[i]){
            break;
        }
    }
    if(i==0){
        cout<<"Not Possible!"<<endl;
        return;
    }
    reverse(digits+i,digits+n);
    swap(digits[i-1],digits[i]);
    cout<<digits<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    char digits[] = "534976";
    int n = strlen(digits);
    findNext(digits, n);
    return 0;
}

