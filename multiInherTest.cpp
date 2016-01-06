#include<iostream>
using namespace std;
class shape{
	protected:
		float l;
		float w;
	public:
		shape():l(0),w(0){}
		shape(float a):l(a),w(a){}
		shape(float a,float b):l(a),w(b){}
		void area(){
			cout<<"area"<<endl;
		}
		void display(){
			cout<<"display"<<endl;
		}
};
class square:public shape{
	protected:
	    float areaOfShape;
	public:
		square(float a):shape(a){}
		void area(){
			areaOfShape = (l*w);
		}
		void display(){
			cout<<"area is "<<areaOfShape<<endl;
		}
};
int main(){
	shape s(3,4);
	s.area();
	s.display();
	square sq(3);
	sq.area();
	sq.display();
}
