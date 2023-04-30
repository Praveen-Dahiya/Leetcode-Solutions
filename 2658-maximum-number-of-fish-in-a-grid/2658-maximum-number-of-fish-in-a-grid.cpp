class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,vector<vector<bool> > & vis,int srci,int srcj){
        
        if(srci<0 || srcj<0 || srci>=grid.size() || srcj>=grid[0].size()){
            return 0;
        }
        if(vis[srci][srcj]==true || grid[srci][srcj]==0){
            return 0;
        }
        
        int ans=0;
        
        vis[srci][srcj]=true;
        ans+=grid[srci][srcj];
        ans+=dfs(grid,vis,srci-1,srcj);
         ans+=dfs(grid,vis,srci,srcj-1);
         ans+=dfs(grid,vis,srci+1,srcj);
         ans+=dfs(grid,vis,srci,srcj+1);
        return ans;
        
        
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool> > vis(n,vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(!vis[i][j] && grid[i][j]>0){
                    // cout<<i<<" "<<j<<"\n";
                    int x=dfs(grid,vis,i,j);
                    ans=max(ans,x);
                }
            }
        }
        return ans;
    }
};