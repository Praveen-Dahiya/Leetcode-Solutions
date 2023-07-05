class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp0(n);
        vector<int> dp1(n);
        
        if(nums[0]==1){
            dp0[0]=1;
        }
        for(int i=1;i<n;i++){
            
            if(nums[i]==1){
                dp0[i]=dp0[i-1]+1;
            }
        }
        if(nums[n-1]==1){
            dp1[n-1]=1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1){
                dp1[i]=dp1[i+1]+1;
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int x=0;
            if((i-1)>=0 ){
                x=dp0[i-1];
            }
            
            if(i+1<n){
                x+=dp1[i+1];
            }
            ans=max(ans,x);
            
            
        }
        return ans;
        
        
    }
};