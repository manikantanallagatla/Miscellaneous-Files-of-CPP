//http://www.sanfoundry.com/cpp-program-implement-avl-trees/
#define pow2(n) (1 << (n))
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
using namespace std;
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;
class avlTree
{
    public:
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, int );
        void display(avl_node *);
      //  void delete(avl_node *);
        avlTree()
        {
            root = NULL;
        }
};
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avlTree::diff(avl_node *temp)
{
        int l_height = height (temp->left);
        int r_height = height (temp->right);
    //    int max_height = max (l_height, r_height);
        int h = l_height-r_height;
    
    return h;
}
avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

avl_node *avlTree::balance(avl_node *temp){
	int balanceFactor = diff(temp);
	if(balanceFactor > 1){
		if(diff(temp->left) >0){
			temp = ll_rotation(temp);
		}
		else{
			temp = lr_rotation(temp);
		}
	}
	else{
		if(diff(temp->right) >0){
			temp = rl_rotation(temp);
		}
		else{
			temp = rr_rotation(temp);
		}
	}
	return temp;
}

avl_node *avlTree :: insert(avl_node *root,int value){
	if(root == NULL){
		root = new avl_node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else{
		if(value<root->data){
			root->left = insert(root->left,value);
			root = balance(root);
		}
		else{
			root->right = insert(root->right,value);
			root = balance(root);
		}
		return root;
	}
}
void avlTree::display(avl_node *ptr)
{
	if(ptr !=NULL){
		display(ptr->left);
		cout<<ptr->data<<" ";
		display(ptr->right);
	}
}
int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root);
            break;
        case 6:
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
