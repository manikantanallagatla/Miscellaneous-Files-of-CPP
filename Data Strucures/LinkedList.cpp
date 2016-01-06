#include<iostream>
using namespace std;
template<class T>
class Node{
	protected:
		T data;
		Node *next;
	public:
		Node(){	}
		void setData(T adata){
			data = adata;
		}
		void setNext(Node *aNext){
			next = aNext;
		}
		T getData(){
			return data;
		}
		Node *getNext(){
			return next;
		}
};
template<class T>
class LinkedList{
	
		Node<T> *head;
	public:
		LinkedList(){
			head = NULL;
		}
		bool isEmpty();
		int getLength();
		int search(T x);
		void insert(T k);
		void Delete();
		void print();
};
template<class T>
int LinkedList<T> :: getLength(){
	Node<T> *temp = head;
	int answer(0);
	if(temp == NULL){
    	return 0;
	}
	while(temp!=NULL){
		answer++;
		temp = temp->getNext();
	}
	return answer;
}
template<class T>
bool LinkedList<T> :: isEmpty(){
if(getLength() == 0){
	return true;
}
else{
	return false;
}
}
template<class T>
void LinkedList<T> :: print(){
	Node<T> *temp = head;
	if(temp == NULL){
		cout << "EMPTY" << endl;
    	return;
	}
	while(temp!=NULL){
		cout<<temp->getData()<<" ";
		temp = temp->getNext();
	}
	cout<<"Done Printing!"<<endl;
}
template<class T>
void LinkedList<T> :: insert(T k ){
	Node<T> *newNode = new Node<T>();
	newNode->setData(k);
	newNode->setNext(NULL);
	Node<T> *temp = head;
	if(head == NULL){
		head = newNode;
	}
	else{
		while(temp->getNext()){
		temp = temp->getNext();
	}
	temp->setNext(newNode);
	}
	
}
template<class T>
int LinkedList<T> :: search(T x ){
	Node<T> *temp = head;
	int index = 0;
	while(temp){
		index++;
		if(temp->getData()==x){
			return index;
		}
		temp = temp->getNext();
	}
	return -1;
}
template<class T>
void LinkedList<T> :: Delete(){
	if(head!=NULL){
		Node<T> *temp = head;
		if(head->getNext() == NULL){
			head = NULL;
		}
		else{
			while(temp->getNext()->getNext()){
				temp = temp->getNext();
			}
			temp->setNext(NULL);
		}
	}
}
typedef LinkedList<int> intList;
void execute(intList * obj,int k){
	switch(k){
		case 1:
			{
			int temp;
			cout<<"Enter element to insert:"<<endl;
			cin>>temp;
			obj->insert(temp);}
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
			obj->Delete();}
			break;
		case 6:
			obj->print();
			break;
	}
}
int main(){
	intList obj;
	int k;
	do{
		cout<<"Enter -1 to exit:"<<endl;
		cout<<"Enter 1 to insert:"<<endl;
		cout<<"Enter 2 to know is empty:"<<endl;
		cout<<"Enter 3 to know length:"<<endl;
		cout<<"Enter 4 to search:"<<endl;
		cout<<"Enter 5 to delete:"<<endl;
		cout<<"Enter 6 to print:"<<endl;
		cin>>k;
		if(k!=-1){
			execute(&obj,k);
		}
	}while(k != -1);
	return 0;
}


