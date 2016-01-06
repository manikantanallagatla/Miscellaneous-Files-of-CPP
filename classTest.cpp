#include<iostream>
using namespace std;
class stud{
	private:
		int rno;
		int rank;
	public:
	void set(int a,int b){
		rno = a;
		rank = b;
	}	
	void display(){
		cout<<rno<<"got "<<"rank "<<rank;
	}	
};
int main(){
	stud sab;
	sab.set(1,1);
	sab.display();
}
