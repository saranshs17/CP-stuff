vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        while(node){
            if(!node->right){
                ans.push_back(node->data);
                node=node->left;
            }else{
                Node * curr=node->right;
                while(curr->left && curr->left!=node){
                    curr=curr->left;
                }
                if(curr->left==NULL){
                    ans.push_back(node->data);
                    curr->left=node;
                    node=node->right;
                }else{
                    curr->left=NULL;
                    node=node->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
