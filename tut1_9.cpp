#include<iostream>
using namespace std;
void function1(int x){
    int y = 0;
    while(x>9){
        y = (y*10)+(x%10);
        x = x/10;
    }
        y = (y*10)+(x%10);

    cout<<y;
}
int main(){
    int x;
    cin>>x;
    function1(x);
return 0;
}
