vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        int level=0;
        while(!dq.empty()){
            int n=dq.size();
            vector<int>temp;
            while(n--){
                if(level%2==0){
                    TreeNode * node=dq.front();
                    dq.pop_front();
                    temp.push_back(node->val);
                    if(node->left)dq.push_back(node->left);
                    if(node->right)dq.push_back(node->right);
                }else{
                    TreeNode * node=dq.back();
                    dq.pop_back();
                    temp.push_back(node->val);
                    if(node->right)dq.push_front(node->right);
                    if(node->left)dq.push_front(node->left);
                }
            }
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
