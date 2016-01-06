#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

/* Helper function that allocates a new
 node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return(node);
}
void populateNext(struct node* p){
    static node *next = NULL;
    if(p!=NULL){
        populateNext(p->right);
        p->next = next;
        next = p;
        populateNext(p->left);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
     /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(12);
    root->left->left  = newnode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    struct node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
    return 0;
}

