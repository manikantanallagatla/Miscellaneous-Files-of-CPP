#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

int getMaximum(int arr[],int start,int end){
    int maximum = INT_MIN;
    int maximum_index = -1;
    for(int i = start;i<=end;i++){
        if(maximum<arr[i]){
            maximum = arr[i];
            maximum_index = i;
        }
    }
    return maximum_index;
}
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
node *buildTree(int in[],int instart,int inend){
    if(instart>inend){
        return NULL;
    }
    int index = getMaximum(in,instart,inend);
    node *tnode = newNode(in[index]);
    if(instart == inend){
        return tnode;
    }
    tnode->left = buildTree(in,instart,index-1);
    tnode->right = buildTree(in,index+1,inend);
    return tnode;
}
int main(){
    ios_base::sync_with_stdio(false);
    /* Assume that inorder traversal of following tree is given
         40
       /   \
      10     30
     /         \
    5          28 */

    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildTree(inorder, 0, len - 1);
    /* Let us test the built tree by printing Insorder traversal */
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}


