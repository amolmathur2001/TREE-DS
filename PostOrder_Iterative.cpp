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
vector<int> PostOrderTraversal(node* root){
    vector<int> ans;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        ans.insert(ans.begin(),temp->data); // insert at the begin() of the vector ans;
        if(temp->left != NULL){
            s.push(temp->left);
        }
        if(temp->right != NULL){
            s.push(temp->right);
        }
    }
    //reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
    
    node* root = new node(10);
    root->left = new node(15);
    root->right = new node(5);
    root->left->right = new node(7);
    root->left->left = new node(3);
    root->right->right  = new node(18);
    vector<int> ans = PostOrderTraversal(root);
    for(auto it : ans){
        cout<<it<<" ";
    }

    



}
