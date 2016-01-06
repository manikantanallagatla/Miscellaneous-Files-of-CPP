#include<iostream>
using namespace std;
class value{
    int x;
public:
    value(){
        x = 0;
    }
    value(int y){
        x = y;
    }
    void enterData(int z){
        x = z;
    }
    void display(){
        cout<<"value is "<<x;
    }
};
int main(){
    value c(5);
//    c((int)5);
    c.display();
    cout<<endl;
    c.enterData(10);
    c.display();
    return 0;
}
