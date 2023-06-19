class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> b(32,0);
        
        for(int i=0;i<nums.size();i++){
            
            for(int j=0;j<32;j++){
                
                if(nums[i] &(1<<j)){
                    b[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(b[i]){
                ans+=(pow(2,i));
            }
        }
        return ans;
    }
};