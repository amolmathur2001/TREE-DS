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
int sum = 0;
node* convertBST(node* root){
    //base conditiion
    
    if(root == NULL){
        return NULL;
    }
    convertBST(root->right);
    //root
    sum = sum + root->data;
    root->data = sum;

    convertBST(root->left); 
    return root;

}
int main(){
    struct node* root = new node(4);
    root->left = new node(1);
    root->left->left  = new node(0);
    root->left->right = new node(2);
    root->left->right->right = new node(3);
    root->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(7);
    root->right->right->right = new node(8);
   node* head = convertBST(root);
   cout<<head->data<<endl;


}
