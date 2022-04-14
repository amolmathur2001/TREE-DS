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
void Preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
node* searchVal(node* root, int val){
    if(root == NULL){return NULL;}
    if(root->data == val){
        return root;
    }
    if(root->data < val){
        return searchVal(root->right,val);
    }
    return searchVal(root->left,val);

}
int main(){
    struct node* root = new node(4);
    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right = new node(7);
    int val;
    cout<<"Enter the value that you want to search : ";
    cin>>val;
    node* head = searchVal(root,val);
    if(head == NULL){
        cout<<"No element is found "<<endl;
    }
    cout<<head->data<<endl;
    Preorder(head);


}
