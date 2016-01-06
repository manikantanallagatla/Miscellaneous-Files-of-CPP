#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void swap(char *a,char *b){
    char *t = a;
    a = b;
    b = t;
}
void permute(char *a, int l, int r){
    if(l == r or l>r){
        cout<<a<<endl;
    }else{
        for(int k = l;k<=r;k++){
            swap(a[l],a[k]);
            permute(a,l+1,r);
            swap(a[l],a[k]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
