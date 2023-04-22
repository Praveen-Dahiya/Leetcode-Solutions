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
       int dp[s.length()][s.length()];
        
        for(int g=0;g<s.length();g++){
            
            for(int j=g,i=0;j<s.length();i++,j++){
                
                if(g==0){
                    dp[i][j]=0;
                }else if(g==1){
                    
                    if(s[i]==s[j]){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=1;
                    }
                }else{
                    
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }else{
                        dp[i][j] = min(1 + dp[i + 1][j], 1 + dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][s.length()-1];
    }
};