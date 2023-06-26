class Solution {
public:
    int dp[1001][2001];
    int rec(vector<vector<int>>& piles, int k,int idx){
        if(idx>=piles.size()){
            if(k==0) return 0;
            return -1e9;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int ans=rec(piles,k,idx+1);
        int fans=0;
        for(int i=1;i<=min((int)piles[idx].size(),k);i++){
            
            fans+=piles[idx][i-1];
            ans=max(ans,fans+rec(piles,k-i,idx+1));
        }
        
        return dp[idx][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(piles,k,0);
    }
};