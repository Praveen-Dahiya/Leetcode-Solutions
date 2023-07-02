
class Solution {
public:

    long long continuousSubarrays(vector<int>& nums) {
      long long ans=0;
        map<int,int> mp;
        
        
        
        int left=0;
        int right=0;
        
        while(right<nums.size()){
            
            mp[nums[right]]++;
            
            while(mp.rbegin()->first -mp.begin()->first >2){
                mp[nums[left]]--;
                
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=(right-left+1);
            
            
            right++;
        }
        return ans;
    }
};
//43