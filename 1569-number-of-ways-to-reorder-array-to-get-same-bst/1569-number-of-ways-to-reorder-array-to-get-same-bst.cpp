class Solution {
public:
     vector<vector<long long>> ncr;
    long long mod = 1e9 + 7;
    int numOfWays(vector<int>& nums) {
        
		int n = nums.size();
        
        ncr.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            ncr[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums);
        return (ans % mod - 1)%mod;
    }
    
private:
   
    long long dfs(vector<int> &nums){
        int n = nums.size();
        if(n==0 || n==1 |n==2){
            return 1;
        }
     
	
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) {
                left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            } 
        }

        long long lAns = dfs(left) % mod;
        long long rAns = dfs(right) % mod;
		

		int left_len = left.size();
        int right_len = right.size();
        // return (((ncr[n - 1][left_len] * lAns) % mod) * rAns) % mod;
        return (((ncr[n - 1][right_len] * lAns) % mod) * rAns) % mod;
    }
};