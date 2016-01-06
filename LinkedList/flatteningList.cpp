#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *right;
    node *down;
};
void push(node ** head,int new_data){
    node *temp = new node;
    temp->data =  new_data;
    temp->down = *head;
    temp->right = NULL;
    *head = temp;
}
void printList(node *head){
    node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->down;
    }
    cout<<endl;
}
node *merge(node *a,node *b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node *result = new node;
    if(a->data<b->data){
        result = a;
        result->down = merge(a->down,b);
    }else{
        result = b;
        result->down = merge(a,b->down);
    }
    return result;
}
node *flatten(node *root){
    if(root == NULL or root->right == NULL){
        return root;
    }
    return merge(root,flatten(root->right));
}
int main(){
    ios_base::sync_with_stdio(false);
    node* root = NULL;

    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);

    // Let us print the flatened linked list
    printList(root);
    return 0;

}
