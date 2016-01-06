#include<iostream>
using namespace std;
class xcord{
	protected:
		int x;
	public:
	    xcord():x(0){};
		xcord(int a):x(a){};
		void display(){
		cout<<"x is"<<x<<endl;
		}
		void move(){
		++x;	
		}		
};
class ycord:public xcord{
	private:
		int y;
	public:
	    ycord():xcord(),y(0){};
		ycord(int a,int b):xcord(a),y(b){};
		void display(){
		cout<<"x is"<<x<<endl;
		cout<<"y is"<<y<<endl;
		}
		void move(){
		++y;	
		}	
};
int main(){
	ycord p(5,10);
	p.display();
}
