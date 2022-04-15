#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left  = right = NULL;

    }
};
node* trimBST(node* root,int low,int high){
    if(root == NULL){
        return NULL;
    }
    if(root->data > high){
        return(trimBST(root->left,low,high));

    }
    if(root->data < low){
        return(trimBST(root->right,low,high));

    }
    root->left = trimBST(root->left,low,high);
    root->right = trimBST(root->right,low,high);

    return root; 




}
void Preorder(node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Preorder(head->left);
    Preorder(head->right);
}
int main(){
    struct node* root = new node(2);
    root->left = new node(1);
    root->right = new node(8);
    root->right->left = new node(6);
    root->right->left->left = new node(5);
    root->right->left->right = new node(7);
    root->right->right = new  node(9);
    int low = 5;
    int high = 7;
    node* head = trimBST(root,low,high);
    cout<<"Root of the new binary Search Tree : "<<head->data<<endl;
    cout<<"Pre order Traversal of the new binary search tree:::::"<<endl;
    Preorder(head);


}
