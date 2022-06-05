/**********This code contains all type of traversals in a tree*********/

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;

  TreeNode(int val){
    data = val;
    left=NULL;
    right=NULL;
  }
};

/******************************Depth First Search (DFS) Techniques************************/

/*******Recursive approach of the tree traversals******/

//Preorder Traversal
vector<int> preorder;

void preorderTraversal(TreeNode* root){
  if(root==NULL) return;
  preorder.push_back(root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

//Inorder Traversal

vector<int> inorder;
void inorderTraversal(TreeNode* root){
  if(root==NULL) return;
  inorderTraversal(root->left);
  inorder.push_back(root->data);
  inorderTraversal(root->right);
}

//Postorder Traversal

vector<int> postorder;
void postorderTraversal(TreeNode* root){
  if(root==NULL) return;
  inorderTraversal(root->left);
  inorderTraversal(root->right);
  postorder.push_back(root->data);
}

/*******Iterative approach of the tree traversals******/

//Preorder traversal
vector<int> preorderTraversal(TreeNode* root){
  vector<int> preorder;
  if(root==NULL) return preorder;
  stack<TreeNode*> st;
  st.push(root);
  while(!st.empty()){
    TreeNode* curr = st.top();
    st.pop();
    preorder.push_back(curr->data);
    //since stack follows LIFO fassion that's why we first push right node then left node
    if(curr->right!=NULL) st.push(curr->right);
    if(curr->left!=NULL) st.push(curr->left);
  }
  return preorder;
}

//Inorder Traversal

vector<int> inorderTraversal(TreeNode* root){
  vector<int> inorder;
  if(root==NULL) inorder;
  stack<TreeNode*> st;
  TreeNode* curr=root;
  while(true){
    if(curr!=NULL){
      st.push(curr);
      curr = curr->left;
    }else{
      if(st.empty()) break;
      TreeNode* node = st.top();
      st.pop();
      inorder.push_back(node->data);
      curr = node->right;
    }
  }
  return inorder;
}

//Postorder traversal

//1. Using 2 stack

vector<int> postorderTraversal(TreeNode* root){
  vector<int> postorder;
  if(root==NULL) return postorder;
  stack<TreeNode*> st1,st2;
  st1.push(root);
  while(!st1.empty()){
    TreeNode* curr = st1.top();
    st1.pop();
    st2.push(curr);
    if(curr->left!=NULL) st1.push(curr->left);
    if(curr->right!=NULL) st1.push(curr->right);
  }
  while(!st2.empty()){
    TreeNode* curr = st2.top();
    st2.pop();
    postorder.push_back(curr->data);
  }
  return postorder;
}

//2. using 1 stack

vector<int> postorderTraversal(TreeNode* root){
  vector<int> postorder;
  if(root==NULL) return postorder;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  while(curr!=NULL || !st.empty()){
    if(curr!=NULL){
      st.push(curr);
      curr = curr->left;
    }else{
      TreeNode* node = st.top();
      if(node->right==NULL){
        st.pop();
        postorder.push_back(node->data);
        while(!st.empty() && node==st.top()->right){
          node = st.top();
          st.pop();
          postorder.push_back(node->data);
        }
      }else curr = node->right;
    }
  }
  return postorder;
}

/***************Pre,Post,In-order traversal using single stack**********************/
vector<int> preorder,inorder,postorder;

void TreeTraversal(TreeNode* root){
  if(root==NULL) return;
  stack<pair<TreeNode*,int>> st;
  st.push({root,1});
  while(!st.empty()){
    auto node = st.top();
    st.pop();
    if(node.second==1){
      preorder.push_back(node.first->data);
      node.second++;
      st.push(node);
      if(node.first->left!=NULL) st.push({node.first->left,1});
    }else if(node.second==2){
      inorder.push_back(node.first->data);
      node.second++;
      st.push(node);
      if(node.first->right!=NULL) st.push({node.first->right,1});
    }else postorder.push_back(node.first->data);
  }
}


/*****************************Breadth First Search (BFS) Technique************************/

vector<vector<int>> BFS(TreeNode* root){
  vector<vector<int>> levels;
  if(root==NULL) return levels;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    vector<int> temp;
    for(int i=0 ; i<q.size() ; i++){
      TreeNode* curr = q.front();
      temp.push_back(curr->data);
      q.pop();
      if(curr->left!=NULL) q.push(curr->left);
      if(curr->right!=NULL) q.push(curr->right);
    }
    levels.push_back(temp);
  }
  return levels;
}

int32_t main(){
  return 0;
}
