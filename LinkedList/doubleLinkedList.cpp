#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
void push(node ** head,int new_data){
    node *temp = new node;
    temp->data =  new_data;
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL){
        (*head)->prev = temp;
    }
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
    temp->prev = prev_node;
    if(temp->next != NULL){
        temp->next->prev = temp;
    }
}
void append(node **head,int new_data){
    node *temp = new node;
    temp = *head;
    node *new_node = new node;
    new_node->data = new_data;
    new_node->next=  NULL;
    new_node->prev = NULL;
    if(temp == NULL){
        *head = new_node;
        return;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new_node;
    temp->prev->next = temp;
    new_node->prev = temp;
    return;
}
void deleteNodePointer(node **head,node *del){
    if(*head == NULL or del == NULL){
        return;
    }
    if(*head == del){
        *head = (*head)->next;
        (*head)->prev = NULL;
    }else{
        if(del->next == NULL){
            del->prev->next = NULL;
        }else{
            node *tmp = del->prev;
            del->prev->next = del->next;
            del->next->prev = tmp;
        }
    }
    free(del);
    return;
}
void reverseList(node **head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        return;
    }
    reverseList(&(*head)->next);
    node *temp = (*head)->next;
    temp->prev = NULL;
    node *ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = *head;
    (*head)->prev = ptr;
    (*head)->next = NULL;
    *head = temp;
    return;
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
    node *head = NULL;
    cout<<"Appending"<<endl;
    append(&head,6);
    cout<<"pushing"<<endl;
    push(&head,7);
    cout<<"pushing"<<endl;
    push(&head,1);
    cout<<"Appending"<<endl;
    append(&head,4);
    cout<<"Insertion After"<<endl;
    insertionAfter(head->next,8);
    cout<<"Created List is ";
    printList(head);

    reverseList(&head);
    printList(head);

    return 0;

}
