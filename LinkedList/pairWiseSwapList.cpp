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
void deleteNodePosition(node **head,int position){
    int n = length(*head);
    if(position>n){
        return;
    }
    node *temp = *head;
    node *prev = NULL;
    for(int i = 0;i<position-1;i++){
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL){
        *head = (*head)->next;
    }else{
        prev->next = temp->next;
    }

}
bool search(node *head,int key){
    if(head == NULL){
        return 0;
    }else{
        if((head)->data == key){
            return 1;
        }
        return search(head->next,key);
    }
}
void swapNodes(node **head,int x,int y){
    node *tempx = *head;
    node *prevx = NULL;
    node *tempy = *head;
    node *prevy = NULL;
    if(x == y){
        return;
    }
    while(tempx){
        if(tempx->data == x){
            break;
        }
        prevx = tempx;
        tempx = tempx->next;
    }
    while(tempy){
        if(tempy->data == y){
            break;
        }
        prevy = tempy;
        tempy = tempy->next;
    }
    if(tempx->data == x and tempy->data == y){
         if (prevx != NULL)
            prevx->next = tempy;
        else // Else make y as new head
            *head = tempy;

   // If y is not head of linked list
   if (prevy != NULL)
       prevy->next = tempx;
   else  // Else make x as new head
       *head = tempx;

   // Swap next pointers
   struct node *temp = tempy->next;
   tempy->next = tempx->next;
   tempx->next  = temp;
    }else{
        return;
    }
}
void deleteList(node **head){
    if(*head == NULL){
        return;
    }
    deleteList(&(*head)->next);
    *head = NULL;
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
void swap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void pairWiseSwap(struct node *head){
    if(head == NULL or head->next == NULL){
        return;
    }
    node *prev = head;
    node *temp = head->next;
    swap(prev->data,temp->data);
    pairWiseSwap(temp->next);
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);

    pairWiseSwap(start);

    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);

    return 0;

}
