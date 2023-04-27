class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        
        for(int i=1;i*i<=n;i++){
            ans+=1;
        }
        return ans;
    }
};