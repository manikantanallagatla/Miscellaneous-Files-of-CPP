#include<iostream>
using namespace std;
template<class T>
class calculator{
	private:
		T a,b;
	public :
	    calculator():a(0),b(0){}
		calculator(T x,T y):a(x),b(y){}
		void display(){
			cout<<"a="<<a<<"  "<<"b="<<b<<endl;
		}	
		T add(){
		return (a+b);	
		}
};
int main(){
	calculator<int> p(3,4);
	p.display();
	cout<<p.add()<<endl;
}
