#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct TreeNode{
   int data;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int val){
       data=val;
       left=NULL;
       right=NULL;
   }
};

//Moris Inorder Traversal 
//T.C O(N), S.C O(1)
//Main idea : before moving toward left connect the rightmost node of left subtree with ///the current node

vector<int> inorderTraversal(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr=root;
    while(curr!=NULL){
        //this case take care if we endup doing left traversal then just add node into our vector
        if(curr->left==NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            //second condition take cares does there any thread present before ..if yes then this means we already traversed the left subtree.
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr = curr->left;
            }else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

//Moris PreOrder Traversal 
//T.C O(N), S.C O(1)

vector<int> preorderTraversal(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr=root;
    while(curr!=NULL){
        //this case take care if we endup doing left traversal then just add node into our vector
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }else{
                prev->right=NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

int_32t main(){
    return 0;
}