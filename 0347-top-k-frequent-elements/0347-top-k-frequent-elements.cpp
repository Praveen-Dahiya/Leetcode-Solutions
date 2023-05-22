class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> mp;;
        
        for(auto &x:nums){
            mp[x]++;
        }
        vector<pair<int,int>> a;
        
        for(auto &x:mp){
            a.push_back({x.second,x.first});
        }
        sort(a.begin(),a.end(),greater<pair<int,int> >());
        
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(a[i].second);
        }
        return ans;
    }
};