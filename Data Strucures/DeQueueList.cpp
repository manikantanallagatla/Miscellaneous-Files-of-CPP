#include<iostream>
using namespace std;
template<class T>
class DeQueueList{
	private:
		int length,maxSize;
		T *array;
	public:
		DeQueueList(int n = 10);
		bool isEmpty(){
			return length == 0;
		}
		int getLength(){
			return length;
		}
		int search(T x);
		DeQueueList<T>& popStart();
		DeQueueList<T>& popEnd();
		DeQueueList<T>& pushStart(int k);
		DeQueueList<T>& pushEnd(int k);
		void print();
};
template<class T>
DeQueueList<T> :: DeQueueList(int n ){
	maxSize = n;
	array = new int[n];
	length = 0;
}
template<class T>
int DeQueueList<T> :: search(T x ){
	for(int i = 0;i<length;i++){
		if(array[i] == x){
			return (i+1);
		}
	}
	 return -1;
}
template<class T>
DeQueueList<T> & DeQueueList<T> :: popStart(){
	if(0<length){
		for(int i = 1;i<length;i++){
			array[i-1] = array[i];
		}
		length--;
	}
	return *this;
}
template<class T>
DeQueueList<T> & DeQueueList<T> :: popEnd(){
	if(0<length){
		length--;
	}
	return *this;
}
template<class T>
DeQueueList<T> & DeQueueList<T> :: pushStart(int k ){
	if(length<maxSize){
		for(int i = length-1;i>=0;i--){
			array[i+1] = array[i];
		}
		array[0] = k;
		length++;
	}
	return *this;
}
template<class T>
DeQueueList<T> & DeQueueList<T> :: pushEnd(int k ){
	if(length<maxSize){
		array[length] = k;
		length++;
	}
	return *this;
}
template<class T>
void DeQueueList<T> :: print(){
	if(length!=0){
		for(int i = 0;i<length;i++){
			cout<<array[i]<<" ";
		}
		cout<<"Completed Printing!"<<endl;
	}
}
typedef DeQueueList<int> intList;
void execute(intList * obj,int k){
	switch(k){
		case 1:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			*obj = obj->pushStart(temp);}
			break;
		case 2:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			*obj = obj->pushEnd(temp);}
			break;
		case 3:
			//int temp;
			{
				
			*obj = obj->popStart();}
			break;
		case 4:
			//int temp;
			{
				
			*obj = obj->popEnd();}
			break;
		case 5:
			if(obj->isEmpty()){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			break;
		case 6:
			cout<<obj->getLength()<<endl;
			break;
		case 7:
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
		case 8:
			obj->print();
			break;
	}
}
int main(){
	intList obj(20);
	int k;
	do{
		cout<<"Enter -1 to exit:"<<endl;
		cout<<"Enter 1 to pushStart:"<<endl;
		cout<<"Enter 2 to pushEnd:"<<endl;
		cout<<"Enter 3 to popStart:"<<endl;
		cout<<"Enter 4 to popEnd:"<<endl;
		cout<<"Enter 5 to know is empty:"<<endl;
		cout<<"Enter 6 to know length:"<<endl;
		cout<<"Enter 7 to search:"<<endl;
		cout<<"Enter 8 to print:"<<endl;
		cin>>k;
		if(k!=-1){
			execute(&obj,k);
		}
	}while(k != -1);
	return 0;
}


