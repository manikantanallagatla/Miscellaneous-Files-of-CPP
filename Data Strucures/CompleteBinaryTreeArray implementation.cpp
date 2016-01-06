#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct BinaryTree{
    int index;
    int depth;
    BinaryTree *left;
    BinaryTree *right;
};
BinaryTree nodes[1001];
int main() {
    nodes[1].index = 1;
    nodes[1].depth = 1;
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int leftIndex;
        int rightIndex;
        cin>>leftIndex>>rightIndex;
        if(leftIndex != -1){
            nodes[i].left = nodes+leftIndex;
            nodes[leftIndex].index = leftIndex;
            nodes[leftIndex].depth = nodes[i].depth+1;
        }
        if(rightIndex != -1){
            nodes[i].right = nodes+rightIndex;
            nodes[rightIndex].index = rightIndex;
            nodes[rightIndex].depth = nodes[i].depth+1;
        }
    }
}

