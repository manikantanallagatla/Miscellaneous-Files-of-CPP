#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define MARKER -1
#define Node node
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
node *newNode(int key){
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->key);

     /* now recur on right child */
     printInorder(node->right);
}
void serialize(node *root,FILE *fp){
    if(root == NULL){
        fprintf(fp,"%d ",MARKER);
        return;
    }
    fprintf(fp,"%d ",root->key);
    serialize(root->left,fp);
    serialize(root->right,fp);
}
void deserialize(node **root,FILE *fp){
    int val;
    if(!fscanf(fp,"%d ",&val) or val == MARKER){
        return;
    }
    *root = newNode(val);
    deserialize(&(*root)->left,fp);
    deserialize(&(*root)->right,fp);
}

int main(){
    ios_base::sync_with_stdio(false);
    // Let us construct a tree shown in the above figure
    struct Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    // Let us deserialize the storeed tree into root1
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deserialize((&root1), fp);

    printf("Inorder Traversal of the tree constructed from file:\n");
    printInorder(root1);//inorder(root1);
    return 0;
}

