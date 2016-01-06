#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     char data;
     struct node* left;
     struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(char data)
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
     cout<<node->data<<" ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     cout<<node->data<<" ";

     /* now recur on right child */
     printInorder(node->right);
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
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     cout<<node->data<<" ";

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}

int height(node *root){
    if(root == NULL){
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    return 1+max(x,y);
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
vector<char> answer;
void printAnswer(){
    if(answer.size() == 0){
        cout<<"Answer empty!!"<<endl;
    }else{
        for(int i = 0;i<answer.size();i++){
            cout<<answer[i];
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
char int2char(int n){
    if(n>=1 and n<=26){
        return char(96+n);
    }return '*';
}
node *buildTreeUtilR(int arr[],int n,int start,int stop);
node *buildTreeUtilL(int arr[],int n,int start,int stop){
    if(start>stop){
        return NULL;
    }
    char dummy = int2char(arr[start]);
    node *temp = newNode(dummy);
    if(start == stop){
        return temp;
    }
    temp->left =  buildTreeUtilL(arr,n,start+1,stop);
    temp->right = buildTreeUtilR(arr,n,start+1,stop);
    return temp;
}
node *buildTreeUtilR(int arr[],int n,int start,int stop){
    if(start>=stop){
        return NULL;
    }
    int x = arr[start];
    x = x*10 + arr[start+1];
    //cout<<x<<endl;
    char dummy = int2char(x);
    if(dummy == '*'){
        return NULL;
    }
    node *temp = newNode(dummy);
    if(start == stop-1){
        return temp;
    }
    temp->left= buildTreeUtilL(arr,n,start+2,stop);
    temp->right = buildTreeUtilR(arr,n,start+2,stop);
    return temp;
}
node *buildTree(int arr[],int n,int start,int stop){
    if(n == 0){
        return NULL;
    }
    if(start >stop){
        return NULL;
    }
    node *root = newNode(' ');
    root->left = buildTreeUtilL(arr,n,start,stop);
    root->right = buildTreeUtilR(arr,n,start,stop);
    return root;
}
void printAllInterpretations(int arr[],int n){
    node *root = buildTree(arr,n,0,n-1);
    printPaths(root);
    //printLevelorder(root);
}
/* Driver program to test above functions*/
int main()
{
     int arr[] = {1,1,3,4};
     int n = sizeof(arr)/sizeof(int);
     printAllInterpretations(arr,n);

     return 0;
}
