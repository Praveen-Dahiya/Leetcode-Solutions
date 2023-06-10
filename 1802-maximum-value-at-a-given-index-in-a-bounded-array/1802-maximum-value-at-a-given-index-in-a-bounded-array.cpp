class Solution {
public:
   
    
    long long sum(long long count, long long val) {
        return val*count - (count*(count+1))/2;
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        long long left  = 1;
        long long right = maxSum;
        
        long long mid_val;
        int ans = 0;
        
        
        while(left <= right) {
            
            mid_val = (left+right)/2;
            
            long long lc = min((long long)index, mid_val-1);
            long long lSum  = sum(lc, mid_val);
            
            lSum += max((long long)0, index - mid_val+1);
            
            long long rc = min((long long)n-index-1, mid_val-1);
            long long rSum  = sum(rc, mid_val);
            
            rSum += max((long long)0, n-index-1 - mid_val+1);
            
            if(lSum + rSum + mid_val <= maxSum) {
                ans = max((long long)ans, mid_val);
                left = mid_val+1;
            } else {
                right = mid_val-1;
            }
            
        }
        
        return ans;
        
    }
};