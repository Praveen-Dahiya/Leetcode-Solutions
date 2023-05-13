class Solution {
public:
int mod=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        long long dp[high+1];
        memset(dp,0ll,sizeof(dp));
        
        dp[0]=1ll;
        
        for(int i=1;i<=high;i++){
            
            if((i-one)>=0){
                dp[i]=(dp[i]%mod+dp[i-one]%mod)%mod;
            }
            if((i-zero)>=0){
                dp[i]=(dp[i]%mod+dp[i-zero]%mod)%mod;
            }
        }
         long long ans=0;
        for(int i=low;i<=high;i++){
            ans=(ans%mod+dp[i]%mod)%mod;
        }
        return (int)ans;
    }
};