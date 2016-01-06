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
void deleteNode(node **head,int key){
    if(*head == NULL){
        return;
    }
    bool found = 0;
    node *temp =  *head;
    node *prev = NULL;
    while(found == 0 and temp){
        if(temp->data == key){
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(found == 0){
        return;
    }
    if(prev == NULL){
        *head = (*head)->next;
    }else{
        prev->next = temp->next;
    }
}
int length(node *head){
    if(head == NULL){
        return 0;
    }
    return (1+length(head->next));
}
void detectAndRemoveLoop(node *head){
    node *tortoise = head;
    node *rabbit = head;
    node *prev = NULL;
    while(tortoise and rabbit){
        prev = rabbit;
        tortoise = tortoise->next;
        rabbit = rabbit->next->next;
        if(rabbit == tortoise){
            break;
        }
    }
    if(rabbit == tortoise){
        prev->next = NULL;
    }
}
node *newNode(int data){
    node *temp = new node;
    temp->data=  data;
    temp->next = NULL;
    return temp;
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
    struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}

