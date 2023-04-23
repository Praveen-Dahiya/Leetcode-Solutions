class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        
        map<int,int> mp;
        if(k>nums.size()) return ans;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        int p=0;
        bool f=false;
        for(auto &y:mp){
            
            p+=y.second;
            if(p>=x && y.first<0){
                f=true;
                ans.push_back(y.first);
                break;
            }
        }
        if(!f){
           ans.push_back(0);
        }
        for(int i=k;i<nums.size();i++){
            
            mp[nums[i-k]]--;
            mp[nums[i]]++;
            
            if(mp[nums[i-k]]==0){
                mp.erase(mp[nums[i-k]]);
            }
            p=0;
            bool f=false;
            for(auto &y:mp){

                p+=y.second;
                if(p>=x && y.first<0){
                     f=true;
                    ans.push_back(y.first);
                    break;
                }
            }
             if(!f){
           ans.push_back(0);
        }
            
        }
        return ans;
    }
};