#include<iostream>
using namespace std;
template<class T>
class QueueList{
	private:
		int length,maxSize;
		T *array;
	public:
		QueueList(int n = 10);
		bool isEmpty(){
			return length == 0;
		}
		int getLength(){
			return length;
		}
		int search(T x);
		QueueList<T>& pop();
		QueueList<T>& push(int k);
		void print();
};
template<class T>
QueueList<T> :: QueueList(int n ){
	maxSize = n;
	array = new int[n];
	length = 0;
}
template<class T>
int QueueList<T> :: search(T x ){
	for(int i = 0;i<length;i++){
		if(array[i] == x){
			return (i+1);
		}
	}
	 return -1;
}
template<class T>
QueueList<T> & QueueList<T> :: pop(){
	if(0<length){
		for(int i = 1;i<length;i++){
			array[i-1] = array[i];
		}
		length--;
	}
	return *this;
}
template<class T>
QueueList<T> & QueueList<T> :: push(int k ){
	if(length<maxSize){
		array[length] = k;
		length++;
	}
	return *this;
}
template<class T>
void QueueList<T> :: print(){
	if(length!=0){
		for(int i = 0;i<length;i++){
			cout<<array[i]<<" ";
		}
		cout<<"Completed Printing!"<<endl;
	}
}
typedef QueueList<int> intList;
void execute(intList * obj,int k){
	switch(k){
		case 1:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			*obj = obj->push(temp);}
			break;
		case 2:
			if(obj->isEmpty()){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			break;
		case 3:
			cout<<obj->getLength()<<endl;
			break;
		case 4:
			{
			int temp;
			cout<<"Enter element to search:"<<endl;
			cin>>temp;
			int index = (obj->search(temp));
			if(index == -1){
				cout<<"Not Found"<<endl;
			}
			else{
				cout<<"Found at "<<(index)<<" position"<<endl;
			}}
			break;
		case 5:
			//int temp;
			{
				
			*obj = obj->pop();}
			break;
		case 6:
			obj->print();
			break;
	}
}
int main(){
	intList obj(20);
	int k;
	do{
		cout<<"Enter -1 to exit:"<<endl;
		cout<<"Enter 1 to push:"<<endl;
		cout<<"Enter 2 to know is empty:"<<endl;
		cout<<"Enter 3 to know length:"<<endl;
		cout<<"Enter 4 to search:"<<endl;
		cout<<"Enter 5 to pop:"<<endl;
		cout<<"Enter 6 to print:"<<endl;
		cin>>k;
		if(k!=-1){
			execute(&obj,k);
		}
	}while(k != -1);
	return 0;
}


