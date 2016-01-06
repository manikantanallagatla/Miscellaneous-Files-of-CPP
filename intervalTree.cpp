#include<iostream>
using namespace std;
struct interval{
	int low,high;
};
struct ItNode{
	interval *i;
	int max;
	ItNode *left, *right;
};
ItNode * newNode(interval i){
	ItNode *temp = new ItNode;
	temp->i = i;
	temp->max = i.high;
	temp->left=  temp->right = NULL;
}
ItNode *insert(ItNode *root, interval i){
	if(root == NULL){
		return newNode()
	}
	int I = root->i->low;
	if(i.low<I){
		root->left
	}
}
int main(){
	
}
