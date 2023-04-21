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
    int ans=0;
    void dfs(TreeNode* root,bool f,int steps){
        if(root==NULL){
            return ;
        }
       
        
        if(f){
            dfs(root->left,!f,steps+1);
            dfs(root->right,f,1);
        }else{
            dfs(root->left,f,1);
            dfs(root->right,!f,steps+1);
        }
        
       ans=max(ans,steps);
        
        
    }
    
    bool f=true;
    int longestZigZag(TreeNode* root) {
        dfs(root,f,0);
        dfs(root,!f,0);
        return ans;
    }
};