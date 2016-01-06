#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *newNode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
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
node *insert(node *root,int data){
    if(root == NULL){
        return (newNode(data));
    }
    if(data<root->data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}
node *minValueNode(node *root){
    node *temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}
node *deleteNode(node *root,int key){
    if(root == NULL){
        return NULL;
    }
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }else{
        if(key>root->data){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->left == NULL){
                node *temp = root->right;
                free(root);
                return temp;
            }else{
                if(root->right == NULL){
                    node *temp = root->left;
                    free(root);
                    return temp;
                }else{
                    node *temp = minValueNode(root->right);
                    root->data = temp->data;
                    root->right = deleteNode(root->right,temp->data);
                    return root;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);

  printInorder(root);
    return 0;
}
