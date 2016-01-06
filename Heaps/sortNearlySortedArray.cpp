#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void swap(int *x,int *y){
    int temp= *x;
    *x = *y;
    *y = temp;
}
class MinHeap{
    int *harr;
    int capacity;
public:

    int heap_size;
    MinHeap(int capacity);
    void minHeapify(int );
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int extractMin();
    void decreaseKey(int i,int new_val);
    int getMin(){
        return harr[0];
    }
    void deleteKey(int i);
    void insertKey(int k);
};
MinHeap::MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout<<"Overflow pls take care!"<<endl;
        return;
    }
    heap_size++;
    int i = heap_size-1;
    harr[i] = k;
    while(i!=0 and harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::decreaseKey(int i,int new_val){
    harr[i] = new_val;
    while(i!=0 and harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}
int MinHeap::extractMin(){
    if(heap_size<=0){
        return INT_MIN;
    }
    if(heap_size ==1){
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
}
void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}
void MinHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size && harr[l]<harr[i]){
        smallest = l;
    }
    if(r<heap_size && harr[r]<harr[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        swap(&harr[i],&harr[smallest]);
        minHeapify(smallest);
    }
}
// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       cout << arr[i] << " ";
   cout << endl;
}
void sortK(int arr[],int n,int k){
    MinHeap h(k+1);
    for(int i = 0;i<k+1;i++){
        h.insertKey(arr[i]);
    }
    int i = k+1;
    int index = 0;
    while(i<n){
        int dummy = h.extractMin();
        arr[index] = dummy;
        index++;
        h.insertKey(arr[i]);
        i++;
    }
    while(h.heap_size!=0){
        int dummy = h.extractMin();
        arr[index] = dummy;
        index++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted array\n";
    printArray (arr, n);
    return 0;
}

