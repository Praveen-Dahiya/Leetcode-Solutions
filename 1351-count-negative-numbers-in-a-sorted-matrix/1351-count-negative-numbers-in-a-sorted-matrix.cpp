class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        
       int i=0;
        int j=grid[0].size()-1;
        
        while(i<grid.size() && j>=0){
            if(grid[i][j]<0){
                ans+=grid.size()-i;
                j--;
            }else{
                i++;
            }
        }
        cout<<ans<<"\n";
        return ans;
    }
};