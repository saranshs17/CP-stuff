void find(Node * node,int &l,int &r,int curr){
        if(node==NULL) return;
        l=min(l,curr);
        r=max(r,curr);
        find(node->left,l,r,curr-1);
        find(node->right,l,r,curr+1);
    }
    void tview(Node * node,vector<int> & ans,vector<int> & level,int index,int currlevel){
        if(node==NULL) return ;
        if(level[index]>currlevel){
            ans[index]=node->data;
            level[index]=currlevel;
        }
        tview(node->left,ans,level,index-1,currlevel+1);
        tview(node->right,ans,level,index+1,currlevel+1);
    }
    vector<int> topView(Node *root)
    {
        int l=0,r=0;
        find(root,l,r,0);
        vector<int> ans(r-l+1,0);
        vector<int> level(r-l+1,INT_MAX);
        tview(root,ans,level,-l,0);
        return ans;
    }
