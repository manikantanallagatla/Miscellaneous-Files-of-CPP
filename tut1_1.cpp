#include<iostream>
using namespace std;
void display(string x){
cout<<x;
}
void function1(){
int x;
cin>>x;
if(x<5000){
    display("Very Poor");
}else{
if(x<10000){
    display("Poor");
}
else{
    display("Rich");
}
}
}
int main(){
function1();
return 0;
}
