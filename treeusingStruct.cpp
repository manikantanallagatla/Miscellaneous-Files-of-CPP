#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct treeNode{
    int a;
    treeNode *left;
    treeNode *right;
};
void generateTree(treeNode **,int );
void infix(struct treeNode *);
void postfix(struct treeNode *);
void prefix(struct treeNode *);
void delete1(struct treeNode **);

int main(){
    ios_base::sync_with_stdio(false);
    treeNode *head  = NULL;
    int choice = 0, num, flag = 0, key;
    do
    {
        printf("\nEnter your choice:\n1. Insert\n2. Traverse via infix\n3.Traverse via prefix\n4. Traverse via postfix\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &num);
            generateTree(&head, num);
            break;
        case 2:
            infix(head);
            break;
        case 3:
            prefix(head);
            break;
        case 4:
            postfix(head);
            break;
        case 5:
            delete1(&head);
            printf("Memory Cleared\nPROGRAM TERMINATED\n");
            break;
        default: printf("Not a valid input, try again\n");
        }
    } while (choice != 5);

    return 0;
}
void generateTree(treeNode **head,int a){
    if(*head == NULL){
        *head = (treeNode *)malloc(sizeof(treeNode));
        (*head)->a = a;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }else{
        treeNode *temp = *head;
        treeNode *prev = *head;
        while(temp){
            if(temp->a <a){
                prev = temp;
                temp = temp->right;
            }else{
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (treeNode *)malloc(sizeof(treeNode));
        temp->a = a;
        temp->left=  temp->right = NULL;
        if(a<prev->a){
            prev->left = temp;
        }else{
            prev->right = temp;
        }
    }
}

void infix(struct treeNode *head)
{
    if (head)
    {
        infix(head->left);
        printf("%d   ", head->a);
        infix(head->right);
    }
}

void prefix(struct treeNode *head)
{
    if (head)
    {
        printf("%d   ", head->a);
        prefix(head->left);
        prefix(head->right);
    }
}

void postfix(struct treeNode *head)
{
    if (head)
    {
        postfix(head->left);
        postfix(head->right);
        printf("%d   ", head->a);
    }
}

void delete1(struct treeNode **head)
{
    if (*head != NULL)
    {
        if ((*head)->left)
        {
            delete(&(*head)->left);
        }
        if ((*head)->right)
        {
            delete(&(*head)->right);
        }
        free(*head);
    }
}
