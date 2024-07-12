/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }else{
                TreeNode * curr=root->left;
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=root;
                    root=root->left;
                }else{
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;
    }
};
