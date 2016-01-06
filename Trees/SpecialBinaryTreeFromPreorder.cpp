#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

node *newNode(char data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void printInorder(node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
static int index = 1;
node *buildTreeUtil(int pre[],char preLN[],int n){
    if(index>=n){
        return NULL;
    }
    node *tnode=  newNode(pre[index]);
    if(preLN[index] == 'L'){
        index++;
        return tnode;
    }
    index++;
    tnode->left = buildTreeUtil(pre,preLN,n);
    tnode->right = buildTreeUtil(pre,preLN,n);
    return tnode;
}
node *buildTree(int pre[],char preLN[],int n){
    node *tnode = newNode(pre[0]);
    if(preLN[0] == 'L'){
        return tnode;
    }
    tnode->left = buildTreeUtil(pre,preLN,n);
    tnode->right = buildTreeUtil(pre,preLN,n);
    return tnode;
    /*
    int index = getMaximum(in,instart,inend);
    node *tnode = newNode(in[index]);
    if(instart == inend){
        return tnode;
    }
    tnode->left = buildTree(in,instart,index-1);
    tnode->right = buildTree(in,index+1,inend);
    return tnode;*/
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    // construct the above tree
    root = buildTree(pre, preLN, n);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);

    return 0;
}



