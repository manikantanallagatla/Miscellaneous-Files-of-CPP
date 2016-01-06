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
bool search(node *root,int n){
    if(root == NULL){
        return 0;
    }
    if(root->data == n){
        return 1;
    }
    bool dummy = search(root->left,n);
    if(dummy == 1){
        return 1;
    }
    return search(root->right,n);
}
int answer = -1;
int findLCA(node *root, int n1, int n2){
    if(root == NULL){
        return 0;
    }
    if(root->data == n1){
        if(search(root->left,n2) or search(root->right,n2)){
            answer = n1;
            return 1;

        }else{
            return -1;
        }
    }else{
        if(root->data == n2){
            if(search(root->left,n1) or search(root->right,n1)){
            answer = n2;
            return 1;
        }else{
            return -1;
        }
        }else{
            int dummy = findLCA(root->left,n1,n2);
            if(dummy ==1){
                return 1;
            }else{
                dummy = findLCA(root->right,n1,n2);
                if(dummy ==1){
                    return 1;
                }else{
                    if(((search(root->left,n1))and(search(root->right,n2)))or ((search(root->right,n1))and(search(root->left,n2)))){
                        answer = root->data;
                        return 1;
                    }else{
                        return -1;
                    }
                }
            }
        }
    }
}
/* Driver program to test above functions*/
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    findLCA(root, 4, 5);
    cout << "LCA(4, 5) = " << answer<<endl;
    //cout<<
    findLCA(root, 4, 6);
    cout << "\nLCA(4, 6) = " << answer<<endl;
    //cout<<answer<<endl;
    findLCA(root, 3, 4);
    cout << "\nLCA(3, 4) = " << answer<<endl;
    //cout<<answer<<endl;
    findLCA(root, 2, 4);
    cout << "\nLCA(2, 4) = " << answer<<endl;
    //cout<<answer<<endl;
    return 0;
}
