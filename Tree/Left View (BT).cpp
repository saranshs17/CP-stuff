vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root==NULL)return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans.push_back(q.front()->data);
        while(n--){
            Node * node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return ans;
}
