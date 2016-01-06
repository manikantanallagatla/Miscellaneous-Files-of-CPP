#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define node_t node
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
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
int minValue(node *root){
    node *temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
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
/* Elements are in an array. The function builds binary tree */
node * binary_search_tree(node *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for(iterator = 0; iterator < size; iterator++)
    {
        root = insert(root, keys[iterator]);
    }

    return root;
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
int index =1;
node *k_smallest_element_inorder(node *root,int k){
    if(root == NULL){
        return NULL;
    }
    node *dummy =     k_smallest_element_inorder(root->left,k);
    if(dummy!=NULL){
        return dummy;
    }
    if(index == k){
        return root;
    }else{
        index++;
        return k_smallest_element_inorder(root->right,k);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    node_t* root = NULL;
    node_t *kNode = NULL;

    int k = 5;
int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    /* Creating the tree given in the above diagram */
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));

    kNode = k_smallest_element_inorder( root, k);
cout<<"Until Here Executed!"<<endl;
    if( kNode )
    {
        printf("kth smallest elment for k = %d is %d", k, kNode->data);
    }
    else
    {
        printf("There is no such element");
    }

    return 0;
}

