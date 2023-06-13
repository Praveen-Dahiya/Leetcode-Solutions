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
         mp[level]+=root->val;
        
        dfs(root->left,level+1);
        dfs(root->right,level+1 );
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> a;
        dfs(root,0);
        for(auto &x:mp){
            a.push_back(x.second);
        }
        sort(a.begin(),a.end(),greater<long long>());
        // for(auto &x:a){
        //     cout<<x<<" ";
        // }
        if(a.size()<k){
            return -1;
        }
        return a[k-1];
    }
};