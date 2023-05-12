class Solution {
public:
    long long dp[100001];
    long long f(vector<vector<int>>& questions,int idx){
        if(idx>=questions.size()){
            return 0;
        }
        
        if(dp[idx] !=-1){
            return dp[idx];
        }
        
         long long f1=questions[idx][0]+f(questions,idx+questions[idx][1]+1);
         long long f2=f(questions,idx+1);
        return dp[idx]=max(f1,f2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return f(questions,0);
    }
};