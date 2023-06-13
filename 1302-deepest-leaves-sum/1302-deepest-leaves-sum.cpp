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
   map<int,long long> mp;
    void dfs(TreeNode* root,int level){
        
        if(root==NULL) return;
        
        if(root->left ==NULL && root->right==NULL){
            mp[level]+=root->val;
            
        }
    
        dfs(root->left,level+1);
        dfs(root->right,level+1 );
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
      
        dfs(root,0);
          for(auto &x:mp){
            ans=x.second;
        }
        return ans;
    }
};