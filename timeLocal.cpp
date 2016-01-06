#include<iostream>
#include<ctime>
using namespace std;
int main(){
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);
	int month = (int)ptr->tm_mon+1;
	int day = (int)ptr->tm_mday;
	int year = (int)ptr->tm_year+1900;
	int hour = (int)ptr->tm_hour;
	int minute = (int)ptr->tm_min;
	int second = (int)ptr->tm_sec;
	cout<<day<<"-"<<month<<"-"<<year<<"::"<<hour<<":"<<minute<<":"<<second<<endl;

}
