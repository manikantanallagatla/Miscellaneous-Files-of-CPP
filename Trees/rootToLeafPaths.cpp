#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
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
vector<int> answer;
void printAnswer(){
    if(answer.size() == 0){
        cout<<"Answer empty!!"<<endl;
    }else{
        for(int i = 0;i<answer.size();i++){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
}
void printPaths(node *root){
    if(root == NULL){
        return;
    }else{
        if(root->left == NULL and root->right == NULL){
            answer.push_back(root->data);
            printAnswer();
            answer.pop_back();
        }else{
            answer.push_back(root->data);
            printPaths(root->left);
            printPaths(root->right);
            answer.pop_back();
        }
    }
}
/* Driver program to test above functions*/
int main()
{
    ios_base::sync_with_stdio(0);
     struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);
     return 0;
}



