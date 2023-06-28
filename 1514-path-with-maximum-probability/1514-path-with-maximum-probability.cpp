class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> graph(n+1);
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        vector<bool> vis(n+1,false);
        while(pq.size()>0){
            auto rem=pq.top();
            pq.pop();
            // cout<<rem.second<<"-->";
            if(rem.second==end) return rem.first;
            if(vis[rem.second]) continue;
            vis[rem.second]=true;
            
            for(auto &nbr:graph[rem.second]){
                
                if(vis[nbr.first]==false){
                    pq.push({rem.first*nbr.second,nbr.first});
                }
            }
        }
        return 0;
    }
};