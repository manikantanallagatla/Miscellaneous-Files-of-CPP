#include<iostream>
#include<cmath>
using namespace std;
class ycord;
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
	friend int dist(xcord,ycord);		
};
class ycord{
	private:
		int y;
	public:
	    ycord():y(0){};
		ycord(int a):y(a){};
		void display(){
		cout<<"y is"<<y<<endl;
		}
		void move(){
		++y;	
		}
	friend int dist(xcord,ycord);	
};
int main(){
	xcord px(5);
	ycord py(10);
	px.display();
	py.display();
	cout<<dist(px,py);
}
int dist(xcord t,ycord u){
	return sqrt((t.x)*(t.x) + (u.y)*(u.y));
}
