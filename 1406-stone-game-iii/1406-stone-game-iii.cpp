class Solution {
public:
    long long dp[100001];
    long long score(vector<int>& stoneValue,int idx){
        if(idx>=stoneValue.size()){
            return 0;
        }
        if(dp[idx]!=LLONG_MAX) return dp[idx];
        long long f1=stoneValue[idx]-score(stoneValue,idx+1);
        
        long long f2=LLONG_MIN;
        
        if(idx+1<stoneValue.size()){
            f2=stoneValue[idx]+stoneValue[idx+1]-score(stoneValue,idx+2);
        }
        
        long long f3=LLONG_MIN;
        
        if(idx+2<stoneValue.size()){
            f3=stoneValue[idx]+stoneValue[idx+1]+stoneValue[idx+2]-score(stoneValue,idx+3);
        }
        
        return dp[idx]=max(f1,max(f2,f3));
        
        
        
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        for(int i=0;i<=1e5;i++){
         dp[i]=LLONG_MAX;
     }
      int x=score(stoneValue,0);
        // cout<<x<<" ";
     
        if(x==0){
                return "Tie";
        }
        if(x>0){
            return "Alice";
        }
        return "Bob";
       
    }
};