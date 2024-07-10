void find(Node * node,int &l,int val){
    if(!node)return;
    l=max(l,val);
    find(node->left,l,val+1);
    find(node->right,l,val);
}
void trav(Node * node,vector<vector<int>> & grid,int level){
    if(!node)return ;
    grid[level].push_back(node->data);
    trav(node->left,grid,level+1);
    trav(node->right,grid,level);
}
vector<int> diagonal(Node *root)
{
    if(!root) return {};
   int l=-1;
   find(root,l,0);
   vector<int> ans;
   if(l==-1)return ans;
   vector<vector<int>> grid(l+1);
   trav(root,grid,0);
   for(int i=0;i<grid.size();++i){
       for(auto x:grid[i]){
          ans.push_back(x);
       }
   }
   return ans;
}
