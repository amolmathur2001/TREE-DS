#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
long long findMaxScore(Node* root)
{
        // Your code goes here
        if(root == NULL){
            return 1;
        }
        long long left_part = (root->data)* findMaxScore(root->left);
        long long right_part = (root->data) * findMaxScore(root->right);
        return(max(left_part,right_part));
}
int main(){
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->right = new Node(4);
    root->right->left = new Node(3);
    cout<<findMaxScore(root);
    


    
}
