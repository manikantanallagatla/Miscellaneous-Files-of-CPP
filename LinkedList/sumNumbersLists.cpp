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
int length(node *head){
    if(head == NULL){
        return 0;
    }
    return (1+length(head->next));
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
    node *ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = *head;
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
void addList(node* head1, node* head2, node** result){
    ll number1 = 0;
    ll number2 = 0;

    node *temp = head1;
    while(temp){
        number1=(number1*10)+(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        number2 = (number2*10)+(temp->data);
        temp = temp->next;
    }
    ll answer = number1+number2;
    cout<<number1<<" "<<number2<<endl;
    while(answer){
        ll dummy = answer%10;
        push(result,dummy);
        answer/=10;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = {9, 9, 9};
    int arr2[] = {1, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create first list as 9->9->9
    int i;
    for (i = size1-1; i >= 0; --i)
        push(&head1, arr1[i]);

    // Create second list as 1->8
    for (i = size2-1; i >= 0; --i)
        push(&head2, arr2[i]);

    addList(head1, head2, &result);

    printList(result);

    return 0;

}

