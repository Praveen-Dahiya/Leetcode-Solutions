class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis,int src){
        if(vis[src]){
            return;
        }
        vis[src]=true;
        
        for(auto &nbr:graph[src]){
            if(!vis[nbr])
            dfs(graph,vis,nbr);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> graph(bombs.size());
        
        for(int i=0;i<bombs.size();i++){
            
            for(int j=0;j<bombs.size();j++){
                if(i==j) continue;
                long double dis= sqrt((long long)(bombs[i][0]- bombs[j][0])*(long long)(bombs[i][0]- bombs[j][0]) + (long long)(bombs[i][1]- bombs[j][1])*(long long)(bombs[i][1]- bombs[j][1]));
              // cout<<dis<<" "<<bombs[i][2]<<"\n";
                if(dis<=(double)(bombs[i][2])){
                    graph[i].push_back(j);
                }
            }
        }
        
//         for(auto &x:graph){
            
//             for(auto &y:x){
//                 cout<<y<<" ";
//             }
//             cout<<"\n";
//         }
        int ans=0;
        for(int i=0;i<bombs.size();i++){
            vector<bool> vis(bombs.size(),false);
            int cans=0;
            dfs(graph,vis,i);
            
            for(int i=0;i<bombs.size();i++){
                if(vis[i]) cans++;
            }
            ans=max(ans,cans);
        }
        return ans;
    }
};