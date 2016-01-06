#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int x){
for(int i = 2;i<x;i++){
    if(x%i == 0){
        return false;
    }
}
return true;
}
void function1(int x){
for(int i = 2;i <= x;i++ ){
        if(isPrime(i) == true){
                if(x%i == 0)
            cout<< i <<endl;
        }
}
}
int main(){
int x;
cin>>x;
function1(x);
return 0;
}
