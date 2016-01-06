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
vector<int> path1;
vector<int> path2;
bool fillPath(node *root,int n,string path){
    if(root == NULL){
        return 0;
    }
    if(path == "path1")
        path1.push_back(root->data);
    else
        path2.push_back(root->data);

    if(root->data == n){
        return 1;
    }
    bool dummy = fillPath(root->left,n,path);
    if(dummy == 1){
        return 1;
    }
    dummy = fillPath(root->right,n,path);
    if(dummy ==1){
        return 1;
    }
    if(path == "path1")
        path1.pop_back();
    else
        path2.pop_back();
    return 0;
}
int findDistance(Node *root, int n1, int n2){
    path1.erase(path1.begin(),path1.end());
    path2.erase(path2.begin(),path2.end());
    fillPath(root,n1,"path1");
    fillPath(root,n2,"path2");
    int index = 0;
    while(index<path1.size() and index<path2.size() and path1[index] == path2[index]){
        index++;
    }
    for(int i = 0;i<path1.size();i++){
        cout<<path1[i]<<" ";
    }cout<<endl;

    for(int i = 0;i<path2.size();i++){
        cout<<path2[i]<<" ";
    }cout<<endl;
    return path1.size()+path2.size()-2*index;
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
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5)<<endl;
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6)<<endl;
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4)<<endl;
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4)<<endl;
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5)<<endl;
     return 0;
}

