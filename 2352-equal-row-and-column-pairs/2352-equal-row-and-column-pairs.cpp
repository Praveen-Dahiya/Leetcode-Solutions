class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
//         for(int i=0;i<n;i++){
         
//             string x="";
//             for(int j=0;j<n;j++){
//                 x+=to_string(grid[i][j])+"+";
//             }
//             mp1[x]++;
//         }
        
        for(int j=0;j<n;j++){
          string x="";
            for(int i=0;i<n;i++){
                x+=to_string(grid[i][j])+"+";
            }
            mp2[x]++;
        }
        // for(auto x: mp1){
        //     cout<<x.first<<" ";
        // }
        // cout<<endl;
        // for(auto x: mp2){
        //     cout<<x.first<<" ";
        // }
        int ans=0;
        for(int i=0;i<n;i++){
         
            string x="";
            for(int j=0;j<n;j++){
                x+=to_string(grid[i][j])+"+";
            }
           if(mp2.find(x)!=mp2.end()){
               ans+=mp2[x];
           }
        }
        return ans;
    }
};