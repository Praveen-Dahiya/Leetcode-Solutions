class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.length();
        map<char,int> mp;
        vector<int> dp(n);
        dp[0]=1;
        mp[s[0]]=max(mp[s[0]],dp[0]);
        for(int i=1;i<n;i++){
            
            char ch=char((s[i-1]-'a'+1)%26+'a');
            if(ch==s[i]){
                dp[i]=dp[i-1]+1;
            }else{
                dp[i]=1;
            }
            mp[s[i]]=max(mp[s[i]],dp[i]);
        }
        int ans=0;
        for(auto &x:mp){
            ans+=x.second;
        }
        return ans;
        
    }
};