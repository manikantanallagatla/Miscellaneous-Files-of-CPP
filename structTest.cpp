#include<iostream>
using namespace std;
struct student{
	int rno;
	float marks;
	char grade;
};
int main(){
	student sab = {1,100,'A'};
	cout<<sab.rno<<sab.marks<<sab.grade;
}
