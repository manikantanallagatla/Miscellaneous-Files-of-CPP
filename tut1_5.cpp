#include<iostream>
using namespace std;
int function(){
int sum = 0;
for(int i=7;i<=21;i++){
    if(i%7 == 0){
        sum = sum + i;
    }
}
return sum;
}
int main(){
int sum = 0;
sum = function();
cout<<sum;
return 0;
}
