#include<iostream>
using namespace std;
class linklist{
	struct node{
		char data;
		struct node * next;
	};
	node * head;
	public:
		linklist(){
        head->data = 'D';
		append('T');
		append('A');
		append(' ');
		append('S');
		append('T');
		append('R');
		append('C');
		append('U');
		append('R');
		append('E');
		append('S');
		append(' ');
		append('I');
		append('T');
		append(' ');
		append('R');
		append('O');
		append('K');
		append('E');       
		}
		void display();
		void append(int);
		void insert(int,int);
};
int main(){
		linklist list;
		cout<<"Given list is"<<endl;
		list.display();
		int k;
		char c;
		int NoOfNew;
		cout<<"Enter number of new characters u want to add"<<endl;
		cin>>NoOfNew;
		for(int i=0;i<NoOfNew;i++){
		cout<<"Enter the position where u want to insert:"<<endl;
		cin>>k;
		cout<<"Enter the character:";
		cin>>c;
		list.insert(k,c);
		cout<<"New list is:"<<endl;
		list.display();
	    }
		list.display();
			}
void linklist::append(int d){
node * newnode = new node;
newnode->data = d;
newnode->next = NULL;
node * newnode1 = new node;
newnode1->data = d;
newnode1->next = NULL;
newnode = newnode1;
node * nodeptr = new node;
		if(head == NULL){
			head = newnode;
		}
		else{
			nodeptr = head;
			while(nodeptr->next!=NULL){
			nodeptr = nodeptr->next;
		}
		nodeptr->next = newnode;
	}
}
void linklist::display(){
	node * dummy = new node;
	dummy = head;
	cout<<head->data;
	while(dummy->next!=NULL){
		dummy = dummy->next;
		cout<<dummy->data;
	}
	cout<<"\n";
}
void linklist::insert(int k,int info){
	node * dupli = new node;
	dupli->data = info;
	node * dummy = new node;
	dummy = head;
	for(int i=0;i<(k-2);i++){
		dummy = dummy->next;
	}
	dupli->next = dummy->next;
	dummy->next = dupli;
}
