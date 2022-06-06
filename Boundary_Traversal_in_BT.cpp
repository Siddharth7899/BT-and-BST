bool isLeaf(Node* node){
      if(node->left==NULL && node->right==NULL) return true;
      return false;
    }
    void inorder(Node* root,vector<int> &leaf){
       if(root==NULL) return;
       inorder(root->left,leaf);
       if(isLeaf(root)) leaf.push_back(root->data);
       inorder(root->right,leaf);
    }
    void leftBoundary(Node* root,queue<int> &q){
        if(root==NULL) return;
        while(!isLeaf(root)){
           q.push(root->data);
           if(root->left!=NULL) root=root->left;
           else if(root->right!=NULL) root=root->right;
        }
    }
    void rightBoundary(Node* root,stack<int> &st){
        if(root==NULL) return;
        while(!isLeaf(root)){
           st.push(root->data);
           if(root->right!=NULL) root=root->right;
           else if(root->left!=NULL) root=root->left;
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<int> q;
        stack<int> st;
        vector<int> leaf;
        if(!isLeaf(root)) ans.push_back(root->data);
        leftBoundary(root->left,q);
        inorder(root,leaf);
        rightBoundary(root->right,st);
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        for(auto e : leaf) ans.push_back(e);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }