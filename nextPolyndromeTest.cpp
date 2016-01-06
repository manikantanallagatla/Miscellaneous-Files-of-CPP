#include<iostream>
using namespace std;
bool isPolyndrome(int a){
    int c = a;
    int b = 0;
    while(a>9){
        b = 10*b + a%10;
        a = a/10;
    }
    b = 10*b + a%10;
    if(b==c){
        return true;
    }
    else{
        return false;
    }
}
void polyndrome(int a){
    a = a+1;
    bool flag = false;
    while(flag == false){
            if(isPolyndrome(a)==true){
                flag = true;
            }
            else{
                a++;
            }
    }
    cout<<a;
}
int main(){
    int x;
    cin>>x;
    polyndrome(x);
}
