void find(TreeNode * node,int &l,int &r,int curr){
        if(node==NULL) return ;
        l=min(l,curr);
        r=max(r,curr);
        find(node->left,l,r,curr-1);
        find(node->right,l,r,curr+1);
    }
    void traverse(TreeNode * node,int index,vector<vector<pair<int,int>>>&temp,int level){
        if(!node) return;
        temp[index].push_back({node->val,level});
        traverse(node->left,index-1,temp,level+1);
        traverse(node->right,index+1,temp,level+1);
    }
    bool static cmp(pair<int,int> a,pair<int,int> b){
        return (a.second==b.second)? a.first<b.first:a.second<b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0;
        find(root,l,r,0);
        vector<vector<pair<int,int>>> temp(r-l+1);
        traverse(root,-l,temp,0);
        vector<vector<int>>ans;
        for(auto x:temp){
            vector<pair<int,int>> t;
            for(auto y:x){
                t.push_back(y);
            }
            sort(t.begin(),t.end(),cmp);
            vector<int> v;
            for(auto x:t){
                v.push_back(x.first);
            }
            ans.push_back(v);
        }
        return ans;
    }
