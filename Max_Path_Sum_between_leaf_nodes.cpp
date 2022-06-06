int maxx=INT_MIN;
    int maxSum(Node* root,Node* par,bool fl,int ind){
        if(root==NULL){
            if(par->left==NULL && par->right==NULL){
                return 0;
            }
            if(fl && ind==1 || ind==2){
               return 0; 
            }
            return -1e9;
        }
        int l = maxSum(root->left,root,fl,2*ind+1);
        int r = maxSum(root->right,root,fl,2*ind+2);
        if(root->left!=NULL || root->right!=NULL) maxx = max(maxx,root->data+l+r);
        return  root->data+max(l,r);
    }
    int maxPathSum(Node* root)
    {
        // code here
        bool fl=false;
        if(root->left==NULL || root->right==NULL) fl=true;
        maxSum(root,root,fl,0);
        return maxx;
    }