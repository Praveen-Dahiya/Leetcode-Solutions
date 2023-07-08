class Solution {
public:
    bool check(int m,int n,int i,int j){
        
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
        
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ans(5);
        
        map<pair<int,int>,int> mp;
        
        
        for(int i=0;i<coordinates.size();i++){
            mp[{coordinates[i][0],coordinates[i][1]}]++;
        }
        map<pair<int,int>,int> mp2;
        for(auto &ele:mp){
                int x=0;
                int i=ele.first.first;
                int j=ele.first.second;
             
                mp2[{i,j}]++;
                mp2[{i,j+1}]++;
                mp2[{i+1,j}]++;
                mp2[{i+1,j+1}]++;
                 mp2[{i-1,j}]++;
                mp2[{i-1,j+1}]++;
                mp2[{i-1,j-1}]++;
                mp2[{i,j-1}]++;
                mp2[{i+1,j-1}]++;
                
                
                
             
             
        }
        // int ans=0;
         for(auto &ele:mp2){
             
             bool add=true;
                int x=0;
                int i=ele.first.first;
                int j=ele.first.second;
             
                
             if(!check(m,n,i,j)) add=false;
                if(mp.find({i,j})!=mp.end()){
                    x++;
                }
              if(!check(m,n,i+1,j)) add=false;
                if(mp.find({i+1,j})!=mp.end()){
                    x++;
                }
              if(!check(m,n,i,j+1)) add=false;
                if(mp.find({i,j+1})!=mp.end()){
                    x++;
                }
              if(!check(m,n,i+1,j+1)) add=false;
                if(mp.find({i+1,j+1})!=mp.end()){
                    x++;
                }
                if(add)
                ans[x]++;
             
             
        }
        
        
        long long d=(long long)(m-1)*(long long)(n-1);
        for(int i=1;i<=4;i++){
            d-=ans[i];
        }
        ans[0]=d;
        return ans;
    }
};