class Solution {
public:
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size()+1][nums2.size()+1];
        
        for(int i=0;i<nums1.size();i++){
            
            for(int j=0;j<nums2.size();j++){
                
                if(nums1[i]==nums2[j]){
                    
                    int f1=0;
                    if(i-1>=0 && j-1>=0){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }else{
                        dp[i][j]=1;
                    }
                }else{
                    
                    int f1=0,f2=0;
                     if(i-1>=0){
                        f1=dp[i-1][j];
                    }
                    
                    if(j-1>=0){
                        f2=dp[i][j-1];
                    }
                    dp[i][j]=max(f1,f2);
                }
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
        
    }
};