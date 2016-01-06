#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define Node node
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
bool identicaltrees(node *a,node *b){
    if(a == NULL and b == NULL){
        return 1;
    }
    if(a == NULL and b != NULL){
        return 0;
    }
    if(a != NULL and b == NULL){
        return 0;
    }
    if(a == b){
        bool dummy = identicaltrees(a->left,b->left);
        if(dummy == 1){
            return identicaltrees(a->right,b->right);
        }
        return 0;
    }
    return 0;

}
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    return 1+max(x,y);
}
void deleteTree(node *root){
    if(root == NULL){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
void mirror(node *root){
    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}
/*
void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
void printLevelorder(node *root){
int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}
*/

void printLevelorder(node *root){
    queue<node *> answer;
    node *temp = root;
    while(temp){
        cout<<temp->data<<" ";
        if(temp->left){
            answer.push(temp->left);
        }
        if(temp->right){
            answer.push(temp->right);
        }
        if(answer.size()!=0){
            node *dummy = answer.front();
            answer.pop();
            temp = dummy;
        }else{
            temp = NULL;
        }
    }
}
int getLeafCount(node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return 1;
    }else{
        return getLeafCount(root->left)+getLeafCount(root->right);
    }
}
int removeShortPathNodesUtil(node **root,int k,int pathlength){
    if(*root == NULL){
        return 0;
    }
    if((*root)->left == NULL and (*root)->right == NULL){
        if(pathlength<k){
            *root = NULL;
            return 1;
        }else{
            return 0;
        }
    }
    if((*root)->left == NULL and (*root)->right != NULL){
        int dummy = removeShortPathNodesUtil(&(*root)->right,k,pathlength+1);
        if(dummy == 1){
            *root = NULL;
            return 1;
        }else{
            return 0;
        }
    }
    if((*root)->left != NULL and (*root)->right == NULL){
        int dummy = removeShortPathNodesUtil(&(*root)->left,k,pathlength+1);
        if(dummy == 1){
            *root = NULL;
            return 1;
        }else{
            return 0;
        }
    }
    if((*root)->left != NULL and (*root)->right != NULL){
        int dummy1 = removeShortPathNodesUtil(&(*root)->right,k,pathlength+1);
        int dummy2 = removeShortPathNodesUtil(&(*root)->left,k,pathlength+1);
        if(dummy1 == 1 and dummy2 ==1){
            *root = NULL;
            return 1;
        }else{
            return 0;
        }
    }
}
void removeShortPathNodes(node **root, int k)
{
    int pathLength = 1;
    removeShortPathNodesUtil(root,k,pathLength);
}
/* Driver program to test above functions*/
int main()
{
    int k = 4;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    cout << "Inorder Traversal of Modified tree" << endl;
    removeShortPathNodes(&root, k);
    printInorder(root);
     return 0;
}

