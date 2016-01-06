#include<iostream>
using namespace std;
class height{
    int feet,inches;
    int i1,i2,f1,f2,s1,s2,d1,d2;
public:
    void enterData(void);
    void addHeight(void);
    void displayData(void);
    void subHeight(void);
};
void height :: enterData(void){
    cout<<"enter first height in feet & inches"<<endl;
	cin>>f1>>i1;
	cout<<"enter 2nd height in feet and inches"<<endl;
	cin>>f2>>i2;
}
void height :: addHeight(void){
    s1 = f1+f2;
    s2 = i1+i2;
    if(s2 > 12){
        s1 = s1+1;
        s2 = s2 - 12;
    }
}
void height :: subHeight(void){
    if(f1 > f2){
        d1 = f1-f2;
        d2 = i1 - i2;
        if(d2 < 0){
            d1 = d1 - 1;
            d2 = d2 + 12;
        }
    }
    else{
        if(f1 = f2){
        d1 = 0;
        d2 = i1 - i2;
        if(d2 < 0){
            d2 = i2 - i1;
        }
        }
        else{
            d1 = f2 - f1;
            d2 = i1 - i2;
            if(d2<0){
                d1 = d1-1;
                d2 = d2 +12;
            }
        }
    }
}
void height :: displayData(void){
    cout<< "Sum = "<<endl;
	cout<<s1<<" \" "<<s2<<" \' "<<endl;
	cout<< "Difference = "<<endl;
	cout<<d1<<" \" "<<d2<<" \' "<<endl;
}
int main(){
    height h1;
    h1.enterData();
    h1.addheight();
	h1.subheight();
	h1.dispdata();
return 0;
}
