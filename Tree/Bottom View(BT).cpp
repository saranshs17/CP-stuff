void find(Node * node,int &l,int &r,int curr){
        if(node==NULL)return ;
        l=min(l,curr);
        r=max(r,curr);
        find(node->left,l,r,curr-1);
        find(node->right,l,r,curr+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        int l=0,r=0;
        find(root,l,r,0);
        vector<int> ans(r-l+1,INT_MAX);
        queue<Node*> q;
        queue<int> pos;
        q.push(root);
        pos.push(-l);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node * node = q.front();
                int curr=pos.front();
                ans[curr]=node->data;
                q.pop();
                pos.pop();
                if(node->left){
                    q.push(node->left);
                    pos.push(curr-1);
                }
                if(node->right){
                    q.push(node->right);
                    pos.push(curr+1);
                }
            }
        }
        return ans;
    }
