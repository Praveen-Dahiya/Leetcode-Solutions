class Solution {
public:
    bool sumInMi(int target,vector<int> &nums,int mi){
        
        int sum=0;
        
        for(int i=0;i<mi;i++){
            sum+=nums[i];
        }
        if(sum>=target) return true;
        
        for(int i=mi;i<nums.size();i++){
            
            sum-=nums[i-mi];
            sum+=nums[i];
             if(sum>=target) return true;
            
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int si=1;
        int ei=nums.size();
        int ans=0;
        while(si<=ei){
            
            int mi=(si+ei)/2;
            
            if(sumInMi(target,nums,mi)){
                ans=mi;
                ei=mi-1;
            }else{
                si=mi+1;
            }
        }
        return ans;
        
        
        
    }
};