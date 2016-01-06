#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *next;
};
void push(node ** head,int new_data){
    node *temp = new node;
    temp->data =  new_data;
    temp->next = *head;
    *head = temp;
}
void insertionAfter(node *prev_node,int new_data){
    if(prev_node == NULL){
        return;
    }
    node *temp = new node;
    temp->data = new_data;
    temp->next = prev_node->next;
    prev_node->next = temp;
}
void append(node **head,int new_data){
    node *temp = new node;
    temp = *head;
    node *new_node = new node;
    new_node->data = new_data;
    new_node->next=  NULL;
    if(temp == NULL){
        *head = new_node;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}
node *getTail(node *head){
    node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    return temp;
}
node *partition(node *head,node *end,node **newHead,node **newEnd){
    node *pivot = end;
    node *temp = head;
    node *prev = NULL;
    node *tail = pivot;
    while(temp!=pivot){
        if(temp->data<pivot->data){
            if(*newHead == NULL){
                *newHead = temp;
            }
            prev = temp;
            temp = temp->next;
        }else{
            if(prev){
                prev->next = temp->next;
            }
            node *tmp = temp->next;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
            temp = tmp;
        }
    }
    if(*newHead == NULL){
        *newHead = pivot;
    }
    *newEnd = tail;
    return pivot;
}
node *quickSortUtil(node *head,node *end){
    if(head == NULL or head == end){
        return head;
    }
    node *newHead = NULL;
    node *newEnd = NULL;
    node *pivot = partition(head,end,&newHead,&newEnd);
    if(newHead != pivot){
        node *tmp = newHead;
        while(tmp->next!=pivot){
            tmp = tmp->next;
        }
        tmp->next = NULL;
        newHead = quickSortUtil(newHead,tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortUtil(pivot->next,newEnd);
    return newHead;
}
void quickSort(struct node **head){
    *head =  quickSortUtil(*head,getTail(*head));
}
void printList(node *head){
    node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "Linked List before sorting \n";
    printList(a);

    quickSort(&a);

    cout << "Linked List after sorting \n";
    printList(a);

    return 0;

}

