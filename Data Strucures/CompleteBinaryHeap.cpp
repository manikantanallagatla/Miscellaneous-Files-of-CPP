#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<iterator>
using namespace std;

class completeBinaryHeap{
	private:
	vector<int> heap;
	int left(int parent);
	int right(int parent);
	int parent(int child);
	public:
	completeBinaryHeap(){
	}
	void insert(int element);
	void deleteElement(int element);
	int searchElement(int element);
	void display();
	int size();
	void preOrder(int index);
	int getHeight();
	int internalNodes(int index);
	//int externalNodes(Node *);
		
};
/*

	
	int completeBinaryHeap::externalNodes(Node *){}

*/
	int completeBinaryHeap::internalNodes(int index){
		if(index>=0 and index<(heap.size())){
			if(left(index)<heap.size() and right(index)<heap.size()){
				return 1+internalNodes(left(index))+internalNodes(right(index));
			}
			else{
				return internalNodes(left(index))+internalNodes(right(index));
			}
		}
		return 0;
	}
void completeBinaryHeap::preOrder(int index){
	if(index>=0 and index<(heap.size())){
		preOrder(left(index));
		cout<<heap[index]<<" ";
		preOrder(right(index));
	}
}
int completeBinaryHeap::getHeight(){
	int height =size();
	height = log(height)/(log(2));
	return height+1;
}
int completeBinaryHeap::size(){
	return heap.size();
}
void completeBinaryHeap::insert(int element){
	heap.push_back(element);
}
void completeBinaryHeap::deleteElement(int element){
	int x = searchElement(element);
	if(x == -1){
		
	}
	else{
		x--;
		heap[x] = heap[heap.size()-1];
		heap.pop_back();
	}
}
int completeBinaryHeap :: searchElement(int element){
	vector<int>::iterator it;
	it = heap.begin();
	int flag = 0;
	int index = 1;
	while(it != heap.end() && (flag == 0)){
		if(*it == element){
			flag = 1;
			return index;
		}
		it++;
		index++;
	}
	return -1;
}
void completeBinaryHeap::display(){
	vector<int>::iterator it;
	it = heap.begin();
	while(it != heap.end()){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}
int completeBinaryHeap::left(int parent){
	int l = 2*parent+1;
	if(l<heap.size()){
		return l;
	}
	return -1;
}
int completeBinaryHeap::right(int parent){
	int l = 2*parent+2;
	if(l<heap.size()){
		return l;
	}
	return -1;
}
int completeBinaryHeap::parent(int child){
	int l = (child-1)/2;
	if(child<=0){
		return -1;
	}
	return l;
}
int main() {
	completeBinaryHeap h;
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on completeBinaryHeap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Element"<<endl;
        cout<<"3.Search Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.get Size"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"7.Get height: "<<endl;
        cout<<"8.PreOrder:"<<endl;
        cout<<"9.Get Number of Internal nodes:"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.insert(element);
            break;
        case 2:
         cout<<"Enter the element to be deleted: ";
            cin>>element;
            h.deleteElement(element);
            break;
        case 3:
            {
            cout<<"Enter the element to be searched: ";
            cin>>element;
           	int x =  h.searchElement(element);
           	if(x == -1){
           		cout<<"Not Found!"<<endl;
           	}
           	else{
           		cout<<"Found at "<<x<<" position"<<endl;
           	}}
           break;
       	case 4:
            cout<<"Displaying elements of Hwap:  ";
            h.display();
            break;
      	case 5:
      		cout<<"Size is ";
      		cout<<h.size()<<endl;
      		break;
	  	case 6:
            exit(1);
            break;
        case 7:
        	cout<<h.getHeight()<<endl;
        	break;
        case 8:
        	h.preOrder(0);
        	break;
        case 9:
        	cout<<h.internalNodes(0)<<endl;
      	default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    return 0;
}

