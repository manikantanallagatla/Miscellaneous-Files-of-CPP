#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
bool isMultipleOf3(int num){
    if(num<0){
        num*=-1;
    }
    if(num == 0){
        return 1;
    }
    if(num ==1){
        return 0;
    }
    int odd = 0;
    int even = 0;
    while(num){
        if(num%2 ==1){
            odd++;
        }
        num = num>>1;
        if(num%2 == 1){
            even++;
        }
        num = num>>1;
    }
    return (isMultipleOf3(abs(odd-even)));
}
int main(){
    ios_base::sync_with_stdio(false);
    int num = 3;
    if (isMultipleOf3(num))
        printf("num is multiple of 3");
    else
        printf("num is not a multiple of 3");
    return 0;
}

