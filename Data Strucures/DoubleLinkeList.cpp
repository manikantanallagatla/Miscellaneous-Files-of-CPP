#include<iostream>
using namespace std;
template<class T>
class Node{
	protected:
		T data;
		Node *next;
		Node *previous;
	public:
		Node(){	}
		void setData(T adata){
			data = adata;
		}
		void setNext(Node *aNext){
			next = aNext;
		}
		void setPrevious(Node *aprevious){
			previous = aprevious;
		}
		T getData(){
			return data;
		}
		Node *getNext(){
			return next;
		}
		Node *getPrevious(){
			return previous;
		}
};
template<class T>
class DoubleLinkedList{
	
		Node<T> *head;
	public:
		DoubleLinkedList(){
			head = NULL;
		}
		bool isEmpty();
		int getLength();
		int search(T x);
		void insertStart(T k);
		void insertEnd(T k);
		void DeleteStart();
		void DeleteEnd();
		void print();
};
template<class T>
int DoubleLinkedList<T> :: getLength(){
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
bool DoubleLinkedList<T> :: isEmpty(){
if(getLength() == 0){
	return true;
}
else{
	return false;
}
}
template<class T>
void DoubleLinkedList<T> :: print(){
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
void DoubleLinkedList<T> :: insertStart(T k ){
	Node<T> *newNode = new Node<T>();
	newNode->setData(k);
	newNode->setPrevious(NULL);
	if(head == NULL){
		newNode->setNext(NULL);
		head = newNode;
	}
	else{
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = newNode;
	}
}
template<class T>
void DoubleLinkedList<T> :: insertEnd(T k ){
	Node<T> *newNode = new Node<T>();
	newNode->setData(k);
	newNode->setNext(NULL);
	Node<T> *temp = head;
	if(head == NULL){
		newNode->setPrevious(NULL);
		head = newNode;
	}
	else{
		while(temp->getNext()){
		temp = temp->getNext();
	}
	temp->setNext(newNode);
	newNode->setPrevious(temp);
	}
}
template<class T>
int DoubleLinkedList<T> :: search(T x ){
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
void DoubleLinkedList<T> :: DeleteStart(){
	if(head!=NULL){
		Node<T> *temp = head;
		if(head->getNext() == NULL){
			head = NULL;
		}
		else{
			head = head->getNext();
			head->setPrevious(NULL);
		}
	}
}

template<class T>
void DoubleLinkedList<T> :: DeleteEnd(){
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
typedef DoubleLinkedList<int> intList;
void execute(intList * obj,int k){
	switch(k){
		case 1:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			obj->insertStart(temp);}
			break;
		case 2:
			{
			int temp;
			cout<<"Enter element to push:"<<endl;
			cin>>temp;
			obj->insertEnd(temp);}
			break;
		case 3:
			//int temp;
			{
				
			obj->DeleteStart();}
			break;
		case 4:
			//int temp;
			{
				
			obj->DeleteEnd();}
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
	intList obj;
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



