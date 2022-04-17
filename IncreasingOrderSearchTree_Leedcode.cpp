#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left  = right = NULL;
    }
};
void Inorder(TreeNode* root, vector<int> &s){
    if(root == NULL){
        return;
    }
    Inorder(root->left,s);
    s.push_back(root->data);
    Inorder(root->right,s);

}
vector<int> PrintInorder(TreeNode* root){
    vector<int> s;
    Inorder(root,s);

    return s;
}
TreeNode* increasingBST(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    vector<int> ans = PrintInorder(root);
    TreeNode* head = new TreeNode(ans[0]);
    TreeNode* temp = head;
    for(int i = 1; i < ans.size(); i++){
        temp->right = new TreeNode(ans[i]);
        temp = temp->right;
        temp->left = NULL;
    }
    return head;
}
int main(){
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    TreeNode* top = increasingBST(root);
    cout<<"root of the left most node is : "<<top->data<<endl;
    //cout<<head->data<<" ";
    vector<int> ans = PrintInorder(top);
    for(auto it : ans){
        cout<<it<<" ";
    }


}
