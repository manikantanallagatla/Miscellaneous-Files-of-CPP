#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
char int2Char(int n){
    char temp =  char(64+n);
    //cout<<temp<<endl;
    return temp;
}
void printString(int n){
    if(n<=26){
        cout<<int2Char(n)<<endl;
        return;
    }
    string answer = "";
    while(n){
    int temp = n%26;
    n/=26;
    if(temp == 0){
        temp = 26;
        n--;
    }
    answer = int2Char(temp) + answer;
    }
    cout<<answer<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    printString(26);
    printString(51);
    printString(52);
    printString(80);
    printString(676);
    printString(702);
    printString(705);
    return 0;
}
