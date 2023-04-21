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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return 0;
        }

        queue<pair<TreeNode*,int >> q;
        
        q.push({root,0ll});
        
        while(q.size()>0){
            
             int mx=INT_MIN,mn=INT_MAX;      
            
             long long s=q.size();
            
            while(s--){
                auto rem=q.front();
                q.pop();
                
                mn=min(rem.second,mn);
                mx=max(rem.second,mx);
                
                if(rem.first->left !=NULL){
                    q.push({rem.first->left,(long long)2*rem.second+1});
                }
                
                if(rem.first->right !=NULL){
                    q.push({rem.first->right,(long long)2*rem.second+2});
                }
            }
            // cout<<mx<<" "<<mn<<"\n";
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};