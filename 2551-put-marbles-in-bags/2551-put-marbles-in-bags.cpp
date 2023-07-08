class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        
        long long minSum=0;
        long long maxSum=0;
        vector<int> a;
        for(int i=0;i<weights.size()-1;i++){
            a.push_back({weights[i]+weights[i+1]});
        }
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<k-1;i++) minSum+=a[i];
         sort(a.begin(),a.end(),greater<int>());
       for(int i=0;i<k-1;i++) maxSum+=a[i];
        // } maxSum+=weights[i];
        
        return maxSum-minSum;
    }
};