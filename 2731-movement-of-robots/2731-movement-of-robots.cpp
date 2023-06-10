class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        
        int n=s.size();
        vector<long long> vals(n);
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                 vals[i]=nums[i]-d;
            } else{
                vals[i]=nums[i]+d;
            }
                
        }
        
        sort(vals.begin(),vals.end());
        
        const int mod=1e9+7;
        long long ans=0ll;
        long long pre=0ll;
        for(int i=0;i<n;i++)
        {
            ans=ans+(i*1ll*vals[i])-pre;
            ans=(ans%mod);
            pre=pre+vals[i];
        }
        
        return ans;
    }
};