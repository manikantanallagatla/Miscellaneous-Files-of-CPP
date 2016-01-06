#include<iostream>
using namespace std;
template<class T>
class StackList{
	private:
		int length,maxSize;
		T *array;
	public:
		StackList(int n = 10);
		bool isEmpty(){
			return length == 0;
		}
		int getLength(){
			return length;
		}
		int search(T x);
		StackList<T>& pop();
		StackList<T>& push(int k);
		void print();
		void printreverse();
};
template<class T>
StackList<T> :: StackList(int n ){
	maxSize = n;
	array = new int[n];
	length = 0;
}
template<class T>
int StackList<T> :: search(T x ){
	for(int i = 0;i<length;i++){
		if(array[i] == x){
			return (i+1);
		}
	}
	 return -1;
}
template<class T>
StackList<T> & StackList<T> :: pop(){
	if(0<length){
		length--;
	}
	return *this;
}
template<class T>
StackList<T> & StackList<T> :: push(int k ){
	if(length<maxSize){
		array[length] = k;
		length++;
	}
	return *this;
}
template<class T>
void StackList<T> :: print(){
	if(length!=0){
		for(int i = 0;i<length;i++){
			cout<<array[i]<<" ";
		}
		cout<<"Completed Printing!"<<endl;
	}
}
template<class T>
void StackList<T> :: printreverse(){
	if(length!=0){
		for(int i = length-1;i>=0;i--){
			cout<<array[i]<<" ";
		}
	}
}
typedef StackList<int> intList;
void execute(intList * obj1,intList * obj2,int k){
	switch(k){
		case 1:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			*obj1 = obj1->push(temp);
			}
			break;
		case 2:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			*obj2 = obj2->push(temp);}
			break;
		case 3:
			//int temp;
			{
				
			obj1->pop();}
			break;
		case 4:
			//int temp;
			{
				
			obj2->pop();}
			break;
		case 5:
			if(obj1->isEmpty() && obj2->isEmpty()){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			break;
		case 6:
			cout<<(obj1->getLength()+obj2->getLength())<<endl;
			break;
		case 7:
			{
			int temp;
			cout<<"Enter element to search:"<<endl;
			cin>>temp;
			int index = (obj1->search(temp));
			if(index == -1){
				index = (obj2->search(temp));
				if(index == -1)
				cout<<"Not Found"<<endl;
				else{
					cout<<"Found at "<<(index)<<" position"<<endl;
				}
			}
			else{
				cout<<"Found at "<<(index)<<" position"<<endl;
			}}
			break;
		case 8:
			obj1->printreverse();
			obj2->print();
			break;
	}
}
int main(){
	intList obj1(20),obj2(20);
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
			execute(&obj1,&obj2,k);
		}
	}while(k != -1);
	return 0;
}

