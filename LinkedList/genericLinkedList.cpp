#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
template<class datatype>
struct node{
    datatype data;
    node *next;
};
template<class datatype>
void push(node<datatype> ** head,datatype new_data){
    node<datatype> *temp = new node<datatype>;
    temp->data =  new_data;
    temp->next = *head;
    *head = temp;
}
template<class datatype>
void printList(node<datatype> *head){
    node<datatype> *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    node<int> *head = NULL;
    push(&head,6);
    push(&head,7);
    push(&head,1);
    push(&head,4);

    cout<<"Created List is ";
    printList(head);
    return 0;
}
