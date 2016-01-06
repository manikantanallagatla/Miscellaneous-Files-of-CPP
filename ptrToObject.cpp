#include<iostream>
using namespace std;
class xcord{
	private:
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
int main(){
	xcord px(5);
	xcord * ptr = &px;
	ptr->display();
	ptr->move();
	ptr->display();
}
