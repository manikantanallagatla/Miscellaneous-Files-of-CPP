//http://www.dailyfreecode.com/code/binary-search-tree-operations-1152.aspx

#include<iostream>
using namespace std;
struct Node{
    int data;
	struct Node *left;
	struct Node *right;
};
class BinarySearchTree{
	public:
		Node *tree;
		BinarySearchTree(){
			tree = NULL;
		}
		void createTree(Node **,int item);
		void postOrder(Node *);
		void preOrder(Node *);
		void inOrder(Node *);
		int getHeight(Node *);
		int totalNodes(Node *);
		int internalNodes(Node *);
		int externalNodes(Node *);
		void removeTree(Node **);
		Node **searchElement(Node **,int);
		void findSmallNode(Node *);
		void findLargestNode(Node *);
		void deleteNode(Node *,int);
};


void BinarySearchTree::removeTree(Node **tree){
	if(*tree!=NULL){
		removeTree(&((*tree)->left));
		removeTree(&((*tree)->right));
		delete *tree;
	}
}
Node ** BinarySearchTree::searchElement(Node **tree,int item){
	if((*tree)->data ==item || (*tree) == NULL){
		return tree;
	}
	else{
		if(((*tree)->data)>item){
			return searchElement(&((*tree)->left),item);
		}
		else{
			return searchElement(&((*tree)->right),item);
		}
	}
}
void BinarySearchTree::findSmallNode(Node *tree){
	if(tree == NULL){
		return;
	}
	if(tree->left == NULL){
		cout<<tree->data;
	}
	else{
		findSmallNode(tree->left);
	}
}
void BinarySearchTree::findLargestNode(Node *tree){
	if(tree == NULL){
		return;
	}
	if(tree->right == NULL){
		cout<<tree->data;
	}
	else{
		findLargestNode(tree->right);
	}
}
void BinarySearchTree::createTree(Node ** tree,int item){
	if((*tree) == NULL){
		(*tree) = new Node;
		(*tree)->data = item;
		(*tree)->left =NULL;
		(*tree)->right = NULL;
	}
	else{
		if(item<(*tree)->data){
			createTree(&((*tree)->left),item);
		}
		else{
			createTree(&((*tree)->right),item);
		}
	}
}
void BinarySearchTree::postOrder(Node *tree){
	if(tree!=NULL){
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<" "<<tree->data;
	}
}
void BinarySearchTree::preOrder(Node *tree){
	if(tree!=NULL){
		preOrder(tree->left);
		cout<<" "<<tree->data;
		preOrder(tree->right);
	}
}
void BinarySearchTree::inOrder(Node *tree){
	if(tree!=NULL){
		cout<<" "<<tree->data;
		inOrder(tree->left);
		inOrder(tree->right);
	}
}
int BinarySearchTree::getHeight(Node *tree){
	if(tree==NULL){
		return 0;
	}
	else{
		int x = getHeight(tree->left);
		int y = getHeight(tree->right);
		return max(x,y)+1;
	}
}
int BinarySearchTree::totalNodes(Node *tree){
	if(tree==NULL){
		return 0;
	}
	else{
		return totalNodes(tree->left)+totalNodes(tree->right)+1;
	}
}
int BinarySearchTree::internalNodes(Node *tree){
	if(tree==NULL || (tree->left == NULL && tree->right == NULL)){
		return 0;
	}
	else{
		return internalNodes(tree->left)+internalNodes(tree->right)+1;
	}
}
int BinarySearchTree::externalNodes(Node *tree){
	if(tree==NULL){
		return 0;
	}
	else{
		if(tree->left == NULL && tree->right == NULL){
			return 1;
		}
		else
		return externalNodes(tree->left)+externalNodes(tree->right);
	}
}
Node *inorderSuccessor(Node *tree){
	if(tree->right == NULL){
		return tree;
	}
	else{
		Node *succ = tree->right;
		if(succ!=NULL){
			while(succ->left!=NULL){
				succ = succ->left;
			}
		}
		return succ;
	}
}
void BinarySearchTree::deleteNode(Node *tree,int item){
	Node *current = tree,*succ,*pred;
	int flag = 0;
	int delcase;
	while(current!=NULL &&(flag == 0)){
		if(current->data == item){
			flag = 1;
		}
		else{
			if(item<current->data){
				pred = current;
				current = current->left;
			}
			else{
				pred = current;
				current = current->right;
			}
		}
	}
	if(current->left == NULL and current->right == NULL){
		delcase = 1;
	}else{
		if(current->left == NULL or current->right == NULL){
			delcase = 2;
		}
		else{
			delcase = 3;
		}
	}
	if(delcase == 1){
		if(pred->left == current){
			pred->left = NULL;
		}
		else{
			pred->right = NULL;
		}
		delete current;
	}
	if(delcase == 2){
		if(pred->left == current){
			if(current->left!=NULL){
				pred->left = current->left;
			}
			else{
				pred->left = current->right;
			}
		}
		else{
			if(current->left!=NULL){
				pred->right = current->left;
			}
			else{
				pred->right = current->right;
			}
		}
		delete current;
	}
	if(delcase ==3){
		succ = inorderSuccessor(current);
		int item1 = succ->data;
		deleteNode(current,item1);
		current->data = item1;
	}
	
}
int main(){
	BinarySearchTree obj;
	Node *ptr = obj.tree;
	Node *ptr1;
	int choice,n,item;
	//BinarySearchTree **ptrptr = &ptr;
	while(1){
       // clrscr();
        cout<<"\n*****BINARY SEARCH TREE OPERATIONS*****\n\n";
        cout<<"1) Create Tree\n";
        cout<<"2) Traversal\n";
        cout<<"3) Height of Tree\n";
        cout<<"4) Total Nodes\n";
        cout<<"5) Internal Nodes \n";
        cout<<"6) External Nodes \n";
        cout<<"7) Remove Tree\n";
        cout<<"8) search element\n";
        cout<<"10) Find Smallest Node\n";
        cout<<"11) Find Largest Node\n";
        cout<<"12) Delete Node\n";
        cout<<"13) Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //Create Tree
                {cout<<"\n\n--Creating Tree--";
                cout<<"\nHow many nodes u want to enter : ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter value : ";
                    cin>>item;
                    obj.createTree(&ptr,item);
                }}
                break;

            case 2 : //All Traversals
                {
                cout<<"\n\nInorder Traversal : ";
                obj.inOrder(ptr);

                cout<<"\n\nPre-order Traversal : ";
                obj.preOrder(ptr);

                cout<<"\n\nPost-order Traversal : ";
                obj.postOrder(ptr);
                //getch();
            }
                break;

            case 3 : //Determining Height of Tree
               {
                int height = obj.getHeight(ptr);
                cout<<"\n\nHeight of Tree : "<<height;
                //getch();
               } break;

            case 4 : //Total nodes in a tree
                {
                int total=obj.totalNodes(ptr);
                cout<<"\n\nTotal Nodes : "<<total;
                //getch();
                }break;

            case 5 : //Internal nodes in a tree
                {
                int total=obj.internalNodes(ptr);
                cout<<"\n\nInternal Nodes : "<<total;
                //getch();
                }break;

            case 6 : //External nodes in a tree
                {
                int total=obj.externalNodes(ptr);
                cout<<"\n\nExternal Nodes : "<<total;
                //getch();
                }break;

            case 7 : //Remove Tree from memory
                {
                obj.removeTree(&ptr);
                cout<<"\n\nTree is removed from Memory";
                //getch();
                }break;

            case 8 : //Inserting a node in a tree
                {
                int x;
                cout<<"Enter element to search:\n";
                cin>>x;
                
                if(obj.searchElement(&ptr,x)!=NULL){
                	cout<<((*obj.searchElement(&ptr,x)))->data<<endl;
                	
                }
				//getch();
                }break;

           

            case 10 : //Find Smallest Node
                {
                cout<<"\n\nSmallest Node is :  ";
                obj.findSmallNode(ptr);
                //getch();
                }break;

            case 11 : //Find Largest Node
                {
                cout<<"\n\nLargest Node is :  ";
                obj.findLargestNode(ptr);
                //getch();
                }break;

            case 12 : //Deleting a node from a tree
                {
                cout<<"\n\n--Deleting a Node from a tree--\n";
                cout<<"Enter value : ";
                cin>>item;
                obj.deleteNode(ptr,item);
                }break;

            case 13 : break;;
        }//end of switch
	}
}









