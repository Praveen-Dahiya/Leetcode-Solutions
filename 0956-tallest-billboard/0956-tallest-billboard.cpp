class Solution {
public:
    
    
    int dp[21][10003];
    int solve(vector<int>& rods, int i, int diff) {

        if (i == rods.size()) {
            if (diff == 0){
                return 0;
            } 

            return -1e9;
        }
        
        if( dp[i][diff+5000] != -1){
            return  dp[i][diff+5000];
        }
            
        
        int ans = 0;

        int nothing = solve(rods, i + 1 , diff);
        int f1  = rods[i] + solve(rods, i + 1 , diff + rods[i]);
        int f2 = rods[i] + solve(rods, i + 1 , diff - rods[i]);

        return dp[i][diff+5000] = max({nothing, f1, f2});
    }
    
    int tallestBillboard(vector<int>& rods) {
    
        
        memset(dp, -1, sizeof(dp));
        
        return solve(rods, 0, 0)/2;
    }
};