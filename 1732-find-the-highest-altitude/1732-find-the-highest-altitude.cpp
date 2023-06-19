class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        
        int fans=0;
        for(int i=0;i<gain.size();i++){
            ans+=gain[i];
            fans=max(ans,fans);
        }
        return fans;
    }
};