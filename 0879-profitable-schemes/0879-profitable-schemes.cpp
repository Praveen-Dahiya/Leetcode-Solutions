class Solution {
public:
  int dp[101][101][101];
    int mod=1000000007;
    int rec(int n,int p,int idx,vector<int>& group, vector<int>& profit){
        
        
        if(idx==group.size()){
           
            if(n>=0 && p<=0){
                return 1;
            }
            return 0;
        }
        if(dp[n][p][idx]!=-1){
            return dp[n][p][idx];
        }
        int f1=0;
        if((n-group[idx])>=0 ){
            f1=rec(n-group[idx],max(0,p-profit[idx]),idx+1,group,profit)%1000000007;
        }  
        int f2=rec(n,p,idx+1,group,profit)%1000000007;
        return dp[n][p][idx]=(f1%1000000007+f2%1000000007)%1000000007;
        
        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return rec(n,minProfit,0,group,profit);
    }
};