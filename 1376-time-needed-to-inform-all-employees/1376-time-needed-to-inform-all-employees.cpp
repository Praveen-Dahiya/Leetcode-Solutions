class Solution {
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int> > tree(n);
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                tree[manager[i]].push_back(i);
            }
        }
        // for(int i=0;i<tree.size();i++){
        //     cout<<i<<"-->";
        //     for(int j=0;j<tree[i].size();j++){
        //         cout<<tree[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        int ans=0;
        while(q.size()){
          int s=q.size();
         
            while(s--){
                auto rem=q.front();
                q.pop();
                ans=max(ans,rem.second);
                 // cout<<rem.first<<" "<<rem.second<<"\n";
                for(auto x: tree[rem.first]){
                    q.push({x,rem.second+informTime[x]});
                }
            }
        }
       
        return ans;
    }
};