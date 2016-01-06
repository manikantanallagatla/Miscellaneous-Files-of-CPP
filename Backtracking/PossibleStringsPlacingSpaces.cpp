#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printPatternUtil(char str[], char buff[],int i,int j,int n){
    if(i==n){
        buff[j] = '\0';
        cout<<buff<<endl;
        return;
    }
    buff[j] = str[i];
    printPatternUtil(str,buff,i+1,j+1,n);
    buff[j] = ' ';
    buff[j+1] = str[i];
    printPatternUtil(str,buff,i+1,j+2,n);
}
void printPattern(char *str){
    int n = strlen(str);
    char buff[2*n];
    buff[0] = str[0];
    printPatternUtil(str,buff,1,1,n);
}
int main(){
    ios_base::sync_with_stdio(false);
    char *str = "ABCD";
    printPattern(str);
    return 0;
}
