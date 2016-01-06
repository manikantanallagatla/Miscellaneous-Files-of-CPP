#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }
struct node *lastNode(node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
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
node* partition(node *l, node *h)
{
    // set pivot as h element
    int x  = h->data;

    // similar to i = l-1 for array implementation
    node *i = l->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}
void _quickSort(struct node* l, struct node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
void quickSort(struct node *head)
{
    // Find last node
    struct node *h = lastNode(head);

    // Call the recursive QuickSort
    _quickSort(head, h);
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

    quickSort(a);

    cout << "Linked List after sorting \n";
    printList(a);
    return 0;

}

