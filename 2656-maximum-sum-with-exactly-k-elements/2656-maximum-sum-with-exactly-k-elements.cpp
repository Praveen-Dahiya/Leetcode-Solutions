class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(auto &x:nums){
            pq.push(x);
        }
        int ans=0;
        
        while(k--){
            
            auto rem=pq.top();
            
            ans+=rem;
            pq.pop();
            pq.push(rem+1);
        }
        return ans;
    }
};