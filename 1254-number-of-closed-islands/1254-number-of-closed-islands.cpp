class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || j>=grid[0].size() ||i>=grid.size() ){
            return false;
        }
          if(grid[i][j]==1){
            return true;
          }
        if(grid[i][j]==-1){
            return true;
        }
        grid[i][j]=-1;
        bool f=dfs(grid,i-1,j);
        bool s=dfs(grid,i,j-1);
        bool t=dfs(grid,i+1,j);
        bool ft=dfs(grid,i,j+1);
        if(!f||!s||!t||!ft){
            return false;
        }
        return true;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
         int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]==0){
                  if (dfs(grid,i,j)==true)ans++;
               }
            }
        }
        return ans;
    }
};