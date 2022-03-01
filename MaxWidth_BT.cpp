//Leetcode Q. 662 Maximum Width of the Binary tree
////The maximum width of a tree is the maximum width among all levels.
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;

    }
};
int levelOrder(TreeNode* root){
   if(root == NULL){
       return -1;
   }
   queue<pair<int,TreeNode*> > q;
   q.push(make_pair(0,root));
   int max_width = 1;
   while(!q.empty()){
       int count = q.size();
       int start = q.front().first;
       int end = q.back().first;
       max_width = max(max_width,end - start + 1);
       //cout<<max_width<<endl;
       for(int i = 0; i < count; i++){
           pair<int,TreeNode*> curr = q.front();
           int idx  = curr.first;
           q.pop();
            if(curr.second->left != NULL)
                    q.push(make_pair(2 * idx + 1, curr.second->left));
                

            if(curr.second->right != NULL)
                    q.push(make_pair(2 * idx + 2,curr.second->right));
       }
    }
    return(max_width);
}
int main(){
    struct node* root = new node(1);
    root->left = new node(3);
    root->right = new node(2);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->right->right = new node(9);
    levelOrder(root);
}
