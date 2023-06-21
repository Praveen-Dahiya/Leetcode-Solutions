class Solution {
public:
     typedef long long ll;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n=nums.size();
        vector<pair<ll,ll>> a(n);
        
        for(int i=0;i<n;i++){
            a[i].first=nums[i];
            a[i].second=cost[i];
        }
        
        sort(a.begin(),a.end());
        
        vector<ll> prefix(n);
        vector<ll> suffix(n);
        prefix[0]=a[0].second;
        suffix[n-1]=a[n-1].second;
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+a[i].second;
        }
        
        ll cur=0;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+a[i].second;
        }
        
        for(int i=0;i<n;i++){
            
            cur+=(abs(a[0].first-a[i].first))*a[i].second;
        }
        
        ll fans=cur;
        // cout<<cur<<"\n";
        for(int i=1;i<n;i++){
            
            cur+=(a[i].first-a[i-1].first)*(prefix[i-1]-suffix[i]);
            fans=min(fans,cur);
            // cout<<cur<<"\n";
        }
        return fans;
        
        
        
    }
};