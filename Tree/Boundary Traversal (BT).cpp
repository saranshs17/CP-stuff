void trav_left(Node * node,vector<int> & left){
        if(!node || (!node->left && !node->right))return;
        left.push_back(node->data);
        if(node->left){
            trav_left(node->left,left);
        }else trav_left(node->right,left);
        
        
    }
    void trav_right(Node * node,vector<int> & right){
        if(!node || (!node->left && !node->right))return;
        if(node->right){
            
            trav_right(node->right,right);
        }else{
            trav_right(node->left,right);
        }
        
        
        right.push_back(node->data);
    }
    void trav(Node * node,vector<int> & leaf){
        if(!node)return;
        if(!node->left && !node->right) leaf.push_back(node->data);
        trav(node->left,leaf);
        trav(node->right,leaf);
    }
    vector <int> boundary(Node *root)
    {
        if(!root) return {};
        if(!root->left && !root->right) return {root->data};
        vector<int> left;
        trav_left(root->left,left);
        vector<int> right;
        trav_right(root->right,right);
        vector<int> leaf;
        trav(root,leaf);
        vector<int> ans;
        ans.push_back(root->data);
        for(auto x:left)ans.push_back(x);
        for(auto x:leaf)ans.push_back(x);
        for(auto x:right)ans.push_back(x);
        return ans;
    }
