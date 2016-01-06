#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define newnode newNode
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int data;
     struct node* left;
     struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);

     /* now recur on right child */
     printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}
int size(node *root){
    if(root == NULL){
        return 0;
    }
    return size(root->left)+size(root->right)+1;
}
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    return 1+max(x,y);
}
node *findNode(node *s,int data){
    if(s == NULL){
        return NULL;
    }
    if(s->data == data){
        return s;
    }
    node *temp = findNode(s->left,data);
    if(temp == NULL){
        temp = findNode(s->right,data);
        return temp;
    }return temp;
}
bool isSubtreeUtil(node *T,node *S){
    if(T == NULL and S == NULL){
        return 1;
    }
    if(T != NULL and S == NULL){
        return 0;
    }
    if(T == NULL and S != NULL){
        return 0;
    }
    if(T->data!=S->data){
        return 0;
    }
    bool dummy = isSubtreeUtil(T->left,S->left);
    if(dummy ==1){
        return isSubtreeUtil(T->right,S->right);
    }
    return 0;
}
bool isSubtree(node *T,node *S){
    if(T == NULL and S!=NULL){
        return 0;
    }
    node *temp = findNode(S,T->data);
    if(temp == NULL){
        return 0;
    }
    return isSubtreeUtil(T,temp);
}

/* Driver program to test above functions*/
int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);


    if (isSubtree(S,T))
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");


     return 0;
}



