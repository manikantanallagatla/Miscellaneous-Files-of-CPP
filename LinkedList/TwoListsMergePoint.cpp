#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node
{
  int data;
  struct node* next;
};
int getCount(struct node* head)
{
  struct node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}
int _getIntersectionNode(int d,node *head1,node *head2){
    node *temp1 = head1;
    for(int i = 0;i<d;i++){
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while(temp1 and temp2){
        if(temp1 == temp2){
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
int getIntersection(node *head1,node *head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    if(c1>c2){
        d = c1-c2;
        return _getIntersectionNode(d,head1,head2);
    }else{
        d = c2-c1;
        return _getIntersectionNode(d,head2,head1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  printf("\n The node of intersection is %d \n",
          getIntersection(head1, head2));

    return 0;
}

