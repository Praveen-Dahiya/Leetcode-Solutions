class Solution {
public:
    int fans=0;
    int knapsack(vector<int>& nums,int idx,int mask){
        
        if(idx>=nums.size()){
            int ans=0;
            for(int i=0;i<21;i++){
                
                if(mask &(1<<i)){
                    fans^=nums[i];
                    ans^=nums[i];
                }
                
            }
            return ans;
        }
        
        int f1=knapsack(nums,idx+1,(1<<idx)|mask);
        int f2=knapsack(nums,idx+1,mask);
        
        return f1+f2;
    }
    int subsetXORSum(vector<int>& nums) {
        return knapsack(nums,0,0);
      
    }
};