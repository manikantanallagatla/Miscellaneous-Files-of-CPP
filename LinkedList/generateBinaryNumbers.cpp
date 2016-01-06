#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void generatePrintBinary(int n){
    queue<string> answer;
    answer.push("1");
    for(int i = 1;i<=n;i++){
        string dummy = answer.front();
        answer.pop();
        cout<<dummy<<endl;
        string dummy1 = dummy+"0";
        answer.push(dummy1);
        dummy1 = dummy+"1";
        answer.push(dummy1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 10;
    generatePrintBinary(n);
    return 0;
}
