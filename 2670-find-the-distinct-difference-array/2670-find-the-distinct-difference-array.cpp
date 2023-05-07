class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        vector<int> ans(nums.size()),prefix(nums.size());
        
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            
            prefix[i]=st.size();
        }
        st.clear();
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=prefix[i]-st.size();
            st.insert(nums[i]);
        }
        return ans;
    }
};