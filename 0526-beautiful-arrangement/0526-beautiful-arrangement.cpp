class Solution {
public:
    int dp[15][(1<<15) +1];
    int rec(int n,int mask,int idx){
       
        if(idx>=n){
            return 1;
        }
        if(dp[idx][mask] !=-1){
            return dp[idx][mask];
        }
        int ans=0;
        
        for(int i=1;i<=n;i++){
             
            if(((idx+1)%i)==0 || (i%(idx+1))==0){
                
                if(( mask &(1<<(i-1)))==0){
                    ans+=rec(n,mask|(1<<(i-1)),idx+1);
                }
            }
        }
        return dp[idx][mask]=ans;
        
        
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n,0,0);
    }
};