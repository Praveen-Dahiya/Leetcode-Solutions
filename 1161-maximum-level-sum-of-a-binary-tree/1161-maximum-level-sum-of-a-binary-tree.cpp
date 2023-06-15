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
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
        int lev=0;
        int maxlev=0;
        int maxsum=INT_MIN;
        while(q.size()>0){
            int sum=0;
            lev++;
            int s=q.size();
            while(s--){
                auto rem=q.front();
                q.pop();
                sum+=rem->val;
              if(rem->left !=NULL){
                  q.push(rem->left);
              }
              if(rem->right !=NULL){
                  q.push(rem->right);
              }
                
            }
            if(sum>maxsum){
                maxsum=sum;
                maxlev=lev;
            }
        }
        return maxlev;
    }
};