vector<int> getPreOrderTraversal(TreeNode *root)
{
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans;
        while(root){
            if(!root->left){
                ans.push_back(root->data);
                root=root->right;
            }else{
                TreeNode * curr=root->left;
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    ans.push_back(root->data);
                    curr->right=root;
                    root=root->left;
                }else{
                    root=root->right;
                }
            }
        }
        return ans;
}
