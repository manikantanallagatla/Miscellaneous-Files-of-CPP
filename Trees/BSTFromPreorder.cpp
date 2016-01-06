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
int findNextMaxindex(int pre[],int val,int l,int r){
    for(int i = l;i<=r;i++){
        if(val<pre[i]){
            return i;
        }
    }
    return INT_MAX;
}
node *constructTree(int pre[],int preStart,int preStop){
    if(preStart>preStop){
        return NULL;
    }
    node *root = newNode(pre[preStart]);
    if(preStart == preStop){
        return root;
    }
    int index = findNextMaxindex(pre,pre[preStart],preStart+1,preStop);
    if(index>=(preStart+1) and index<=preStop){
        root->left = constructTree(pre,preStart+1,index-1);
        root->right =  constructTree(pre,index,preStop);
        return root;
    }else{
        root->right = NULL;
        root->left = constructTree(pre,preStart+1,preStop);
        return root;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = constructTree(pre, 0,size-1);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
    return 0;
}
