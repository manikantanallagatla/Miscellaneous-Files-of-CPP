#include<iostream>
using namespace std;
class stud{
	private:
		int rno;
		int rank;
	public:
	stud():rno(0),rank(0){}
	stud(int a,int b):rno(a),rank(b){}
	void display();
};
int main(){
	stud sab(1,1);
	//sab.stud(1,1);
	sab.display();
}
	//stud::stud(int a,int b){
	//	rno = a;
	//	rank = b;
	//}
	void stud::display(){
		cout<<rno<<"got "<<"rank "<<rank;
	}
