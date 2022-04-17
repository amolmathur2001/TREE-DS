#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data  = val;
        left = right = NULL;

    }
};
bool is_leaf(node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}
void printRootToLeaf(node* root,vector<int> &path){
    //base case
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(is_leaf(root)){
        for(auto it : path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    printRootToLeaf(root->left,path);
    printRootToLeaf(root->right,path);

    path.pop_back();

}
void printAns(node* root){
    vector<int> path;
    printRootToLeaf(root,path);
}
int main(){
    struct node* root = new node(1);
    root->left = new node(0);
    root->right = new node(1);
    root->left->left = new node(0);
    root->left->right = new node(1);
    root->right->left = new node(0);
    root->right->right = new node(1);
    printAns(root);


}
