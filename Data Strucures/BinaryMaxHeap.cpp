#include <iostream>
#include<stdlib.h>
#include<vector>
#include<iterator>
using namespace std;

class BinaryMaxHeap{
	private:
	vector<int> heap;
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyUp(int index);
	void heapifyDown(int index);
	public:
	BinaryMaxHeap(){
		
	}
	void insert(int element);
	void deleteMin();
	int extractMin();
	void display();
	int size();
};
int BinaryMaxHeap::size(){
	return heap.size();
}
void BinaryMaxHeap::insert(int element){
	heap.push_back(element);
	heapifyUp(heap.size()-1);
}
void BinaryMaxHeap::deleteMin(){
	if(heap.size()>0){
		heap[0] = heap[heap.size()-1];
		heap.pop_back();
		heapifyDown(0);
		cout<<"Deleted"<<endl;
	}
}
int BinaryMaxHeap::extractMin(){
	if(heap.size()>0){
		return heap.front();
		}
		else{
			return -1;
		}
}
void BinaryMaxHeap::display(){
	vector<int>::iterator it;
	it = heap.begin();
	while(it != heap.end()){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}
int BinaryMaxHeap::left(int parent){
	int l = 2*parent+1;
	if(l<heap.size()){
		return l;
	}
	return -1;
}
int BinaryMaxHeap::right(int parent){
	int l = 2*parent+2;
	if(l<heap.size()){
		return l;
	}
	return -1;
}
int BinaryMaxHeap::parent(int child){
	int l = (child-1)/2;
	if(child<=0){
		return -1;
	}
	return l;
}
void BinaryMaxHeap::heapifyUp(int n){
	if(n>=0 &&parent(n)>=0 && heap[parent(n)] < heap[n]){
		int temp = heap[n];
		heap[n] = heap[parent(n)];
		heap[parent(n)] = temp;
		heapifyUp(parent(n));
	}
}
void BinaryMaxHeap::heapifyDown(int n){
	int child1 = left(n);
	int child2 = right(n);
	if(child2 >=(heap.size()) and child1>=(heap.size())){
		return;
	}
	if(child2 >=(heap.size())){
		child2 = child1;
	}
	
	
	if(heap[n]<heap[child1] || heap[n]<heap[child2]){
		if(child1>=0 &&child2>=0 && heap[child1]<heap[child2]){
		child1 = child2;
	}
	if(child1>=0){
		int temp = heap[child1];
		heap[child1] = heap[n];
		heap[n] = temp;
		heapifyDown(child1);
	}
	}
}


int main() {
	BinaryMaxHeap h;
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Extract Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Exit"<<endl;
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
         h.deleteMin();
            break;
        case 3:
            cout<<"Minimum Element: ";
            if (h.extractMin() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }

            else
            cout<<"Minimum Element:  "<<h.extractMin()<<endl;
           break;
       case 4:
            cout<<"Displaying elements of Hwap:  ";
            h.display();
            break;
      case 5:
            exit(1);
      default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    return 0;
}

