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
    TreeNode *f=NULL;
    void dfs(unordered_map<TreeNode*,vector<TreeNode*> > & tree, TreeNode *src,int dis,TreeNode *par){
       
         // cout<<src->val<<"-->";
        if(dis>=0 && tree[src].size()==1 && par!=NULL && src!=f){
            
            ans+=1;
        }
        
        for(auto &x:tree[src]){
             if(x !=par)
            dfs(tree,x,dis-1,src);
        }
        
    }
    void makeTree(TreeNode *root, unordered_map<TreeNode*,vector<TreeNode*> > & tree){
        
        if(root==NULL){
            return;
        }
        
        if(root->left !=NULL){
            tree[root].push_back(root->left);
            tree[root->left].push_back(root);
        }
        if(root->right !=NULL){
            tree[root].push_back(root->right);
            tree[root->right].push_back(root);
        }
        makeTree(root->left,tree);
        makeTree(root->right,tree);
        
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*> > mp;
        f=root;
        makeTree(root,mp);
        for(auto &x:mp){
            
           if(x.second.size()==1 && x.first !=f){
               dfs(mp,x.first,distance,NULL);
               // cout<<"\n";
           }
            
        }
        // cout<<"\n";
        return ans/2;
        
    }
};