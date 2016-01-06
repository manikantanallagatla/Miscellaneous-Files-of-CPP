#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
    int height;
};
int height(node *n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}
node *newNode(int key){
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}
node *rightRotate(node *y){
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}
node *leftRotate(node *x){
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
int getBalance(node *n){
    if(n == NULL){
        return 0;
    }
    return (height(n->left)-height(n->right));
}
void preOrder(node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
node *insert(node *root,int key){
    if(root == NULL){
        return newNode(key);
    }
    if(key<root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    root->height = max(height(root->left),height(root->right))+1;
    int balance = getBalance(root);
    if(balance>1 and key<root->left->key){
        return rightRotate(root);
    }
    if(balance<-1 and key>root->right->key){
        return leftRotate(root);
    }
    if(balance>1 and key>root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 and key<root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node *root = NULL;

  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    cout<<("Pre order traversal of the constructed AVL tree is \n");
    preOrder(root);



    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    cout<<("\nPre order traversal after deletion of 10 \n");
    preOrder(root);
    return 0;
}
