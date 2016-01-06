#include<iostream>
using namespace std;
class base{
	protected:
		int * ptr;
	public:
	base(){
		ptr = new int(10000);
		cout<<"Base constructor"<<endl;
	}	
	void display(){
		cout<<"Base"<<endl;
	}
	~base(){
	delete ptr;
		cout<<"Base destructor"<<endl;
	}
};
class derived:public base{
		protected:
		int * ptr1;
	public:
	derived(){
		ptr1 = new int(30000);
		cout<<"derived constructor"<<endl;
	}	
	void display(){
		cout<<"derived"<<endl;
	}
	~derived(){
		delete ptr1;
		cout<<"derived destructor"<<endl;
	}
};
int main(){
	base * p = new derived;
	delete p;
}
