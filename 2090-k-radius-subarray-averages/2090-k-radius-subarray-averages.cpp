class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        
        if(2*k+1 >nums.size()){
            for(auto &x:nums) x=-1;
            return nums;
        }
        vector<int> ans;
        
        long long sum=0;
        for(int i=0;i<min((int)k,(int)nums.size());i++){
            ans.push_back(-1);
        }
    k=2*k+1;
        for(int i=0;i<min((int)k,(int)nums.size());i++){
            // ans.push_back(-1);
            sum+=nums[i];
        }
                    ans.push_back(sum/(k));

        for(int i=min(k,(int)nums.size());i<nums.size();i++){
            
            sum-=nums[i-k];
            sum+=nums[i];
            ans.push_back(sum/(k));
        }
        while(ans.size()<nums.size()) ans.push_back(-1);
        return ans;
    }
};