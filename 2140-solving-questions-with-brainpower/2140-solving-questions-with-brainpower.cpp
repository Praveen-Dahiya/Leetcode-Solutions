class Solution {
public:
   
//     long long f(vector<vector<int>>& questions,int idx){
//         if(idx>=questions.size()){
//             return 0;
//         }
        
//         if(dp[idx] !=-1){
//             return dp[idx];
//         }
        
//          long long f1=questions[idx][0]+f(questions,idx+questions[idx][1]+1);
//          long long f2=f(questions,idx+1);
//         return dp[idx]=max(f1,f2);
//     }
    long long mostPoints(vector<vector<int>>& questions) {
         long long dp[1000000]={0};
        long long ans=0;
        for(int i=questions.size()-1;i>=0;i--){
            dp[i]=max(questions[i][0]+dp[questions[i][1] + i + 1],dp[i+1]);
            
        }
        cout<<dp[0];
        
        return dp[0];
    }
};