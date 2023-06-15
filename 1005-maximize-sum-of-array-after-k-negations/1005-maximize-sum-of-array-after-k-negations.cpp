class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(auto &x:nums){
            pq.push(-x);
        }
        for(int i=0;i<k;i++){
            
            int x= (pq.top());
            pq.pop();
            pq.push(-x);
            
            
            
        }
        int ans=0;
        
        while(pq.size()>0){
            ans-=pq.top();
            pq.pop();
        }
        return ans;
    }
};