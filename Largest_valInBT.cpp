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
void LevelOrder(node* root){
    //Base condition;
    if(root == NULL){
        return;
    }
    queue<node*> q;
    vector<int> ans;
    q.push(root);
    while(q.size() != 0){
        int size = q.size();
        int maxi = INT_MIN;
        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();
            if(temp->data > maxi){
                maxi = temp->data;
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        ans.push_back(maxi);
    }
    for(auto it : ans){
            cout<<it<<" ";
        }


}
int main(){
    struct node* root = new node(4);
    root->left = new node(9);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->right = new node(7);
    LevelOrder(root);
    

}
