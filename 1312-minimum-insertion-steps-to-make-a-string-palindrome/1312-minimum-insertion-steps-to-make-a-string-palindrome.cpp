class Solution {
public:
    int dp[501][501];
    int palindrome(string &s,int si,int ei){
        
        if(si>=ei){
            return 0;
        }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        int f1=1000;
           int f2=1000;
        if(s[si]==s[ei]){
            f1=palindrome(s,si+1,ei-1);
        }else{
            f1=1+palindrome(s,si+1,ei);
            f2=1+palindrome(s,si,ei-1);
        }
        
        return dp[si][ei]=min(f1,f2);
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return palindrome(s,0,s.length()-1);
    }
};