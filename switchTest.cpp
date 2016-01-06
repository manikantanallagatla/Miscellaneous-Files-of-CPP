#include<iostream>
using namespace std;
int main(){
int x = 1;
switch(x){
case 0 : cout<<"Zero";
break;
case 1 : cout<<"One"<<endl;
break;
default: cout<<"None";
break;
}
(x ==  1) ? cout<<"One" : "None";
return 0;
}
