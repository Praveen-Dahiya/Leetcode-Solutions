int dp[101][101];
class Solution {
public:
    int rec(vector<int>& piles,int m,int idx){
        
        
        if(idx>=piles.size()){
            return 0;
        }
        if(dp[m][idx] !=-1){
            return dp[m][idx];
        }
        int f1=INT_MIN;
        int sum=0;
        for(int i=0;i<2*m;i++){
            
            
            if((idx+i)<piles.size()){
                
                sum+=piles[idx+i];
                    f1=max(sum-rec(piles,max(m,(i+1)),idx+i+1),f1);
                
            }
        }
        
        // cout<<idx<<" "<<f1<<"\n";
        return dp[m][idx]=f1;
        
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int total=0;
        for(int i=0;i<piles.size();i++){
            total+=piles[i];
        }
         int x=rec(piles,1,0);
        int alice=(total+x)/2;
        cout<<x<<"\n";
        
        return alice;
        
      
    }
};