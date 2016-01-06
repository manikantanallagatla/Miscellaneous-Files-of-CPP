#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct node{
    char data;
    int isEndOfString;
    node *left;
    node *right;
    node *equal;
};
node *newNode(char data){
    node *temp = new node;
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->right = temp->equal = NULL;
    return temp;
}
void insert(node **root,char *word){
    if(*root == NULL){
        *root = newNode(*word);
    }
    if((*word)<(*root)->data){
        insert(&(*root)->left,word);
    }else{
        if((*word)>(*root)->data){
        insert(&(*root)->right,word);
    }else{
        if(*(word+1)){
            insert(&(*root)->equal,word+1);
        }else{
            (*root)->isEndOfString = 1;
        }
    }
    }
}

void traverseTSTUtil(node *root,char *buffer,int depth){
    if(root){
        traverseTSTUtil(root->left,buffer,depth);
        buffer[depth] = root->data;
        if(root->isEndOfString){
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }
        traverseTSTUtil(root->equal,buffer,depth+1);
        traverseTSTUtil(root->right,buffer,depth);
    }
}
void traverseTST(node *root){
    char buffer[50];
    traverseTSTUtil(root,buffer,0);
}
int searchTST(node *root,char *word){
    if(root == NULL){
        return 0;
    }
    if(*word<root->data){
        return searchTST(root->left,word);
    }else{
        if(*word>root->data){
            return searchTST(root->right,word);
        }else{
            if(*(word+1) == '\0'){
                return root->isEndOfString;
            }
            return searchTST(root->equal,(word+1));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    struct node *root = NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    printf("Following is traversal of ternary search tree\n");
    traverseTST(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
    searchTST(root, "bu")?   printf("Found\n"): printf("Not Found\n");
    searchTST(root, "cat")?  printf("Found\n"): printf("Not Found\n");

    return 0;
}

