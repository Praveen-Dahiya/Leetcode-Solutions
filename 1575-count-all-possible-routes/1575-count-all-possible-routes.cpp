class Solution {
public:
    int dp[101][20001];
    long long mod=1e9+7;
    int rec(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<0){
            return 0;
        }
        if(dp[start][fuel] !=-1){
            return dp[start][fuel]%mod;
        }
        int ans=0;
        if(start==finish){
            ans+=1;
        }
        
        
        for(int i=0;i<locations.size();i++){
            if(i != start){
               ans=(ans%mod+rec(locations,i,finish,fuel-abs(locations[start]-locations[i]))%mod)%mod; 
            }
        }
        return dp[start][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return rec(locations,start,finish,fuel);
    }
};