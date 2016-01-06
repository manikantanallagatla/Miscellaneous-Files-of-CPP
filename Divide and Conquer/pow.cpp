#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int power(int x, unsigned int y){
    if(y ==0){
        return 1;
    }
    int temp = power(x,(y/2));
    if(y%2 == 0){
        return temp*temp;
    }
    return temp*temp*x;
}
int main(){
    ios_base::sync_with_stdio(false);
    int x = 2;
    unsigned int y = 3;

    printf("%d", power(x, y));
    return 0;
}
