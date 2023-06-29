class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        
        int n=a.size();
        vector<int> dp1(n,0);
        vector<int> dp0(n,0);
        int ans=1;
        for(int i=0;i<n;i++){
            
            int mx=0;
            dp1[i]=1;
            dp0[i]=1;
            if((i-1)>=0){
                
                if(a[i]>a[i-1]){
                    dp0[i]+=dp1[i-1];
                }else if(a[i]<a[i-1]){
                     dp1[i]+=dp0[i-1];
                }
            }
            ans=max({ans,dp0[i],dp1[i]});
            
        }
        return ans;
    }
};