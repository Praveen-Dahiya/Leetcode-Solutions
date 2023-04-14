class Solution {
public:
    int dp[1001][1001];
    int rec(string &s,int idx1,int idx2){
        
        if(idx1>idx2){
            return 0;
        }
        if(idx1==idx2){
            return 1;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int f1=0;
        int f2=0;
        if(s[idx1]==s[idx2]){
            f1=2+rec(s,idx1+1,idx2-1);
        }else{
            f1=rec(s,idx1,idx2-1);
            f2=rec(s,idx1+1,idx2);
        }
        return dp[idx1][idx2]=max(f1,f2);
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(s,0,s.length()-1);
    }
};