class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i-1]+nums[i];
        }
//         for(auto &x:nums){
//             cout<<x<<" ";
            
//         }
//         cout<<"\n";
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            
            int si=0;
            int ei=nums.size()-1;
            int pans=-1;
            while(si<=ei){
                
                int mi=(si+ei)/2;
                
                if(nums[mi]<=queries[i]){
                    si=mi+1;
                    pans=mi;
                }else{
                    ei=mi-1;
                }
            }
            ans[i]=pans+1;
            
            
        }
        return ans;
    }
};