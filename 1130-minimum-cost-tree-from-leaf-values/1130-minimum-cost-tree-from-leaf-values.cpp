class Solution {
public:
    int dp[41][41];
    int rec(vector<int> &arr,int si,int ei, map<pair<int,int>,int> &mp){
        
        if(ei-si ==0){
            return 0;
        }
        // if(ei-si ==1){
        //     return 0;
        // }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        int ans=mp[{si,ei}];
        int fans=1e9;
       
        for(int i=si;i<ei;i++){
            
            int f=rec(arr,si,i,mp)+rec(arr,i+1,ei,mp)+ans;
            fans=min(fans,f);
        }
         // cout<<si<<" "<<ei<<"-->"<<fans<<"\n";
        return  dp[si][ei]=fans;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<arr.size();i++){
            vector<int> mx;
            mx.push_back(arr[i]);
            for(int j=i+1;j<arr.size();j++){
                mx.push_back(arr[j]);
                sort(mx.begin(),mx.end(),greater<int>());
                if(mx.size()>2){
                    mx.pop_back();
                     mp[{i,j}]=mx[0]*mx[1];
                }else if(mx.size()==2){
                     mp[{i,j}]=mx[0]*mx[1];
                }
               
            }
        }
        
        // for(auto &x:mp){
        //     cout<<x.first.first<<" "<<x.first.second<<"-->"<<x.second<<"\n"; 
        // }
        return rec(arr,0,arr.size()-1,mp);
    }
};