class Solution {
public:
    void dfs(vector<vector<int>> & graph,vector<bool> & visited,int src){
        visited[src]=true;
        for(int nbr: graph[src]){
            if(visited[nbr]==false){
                dfs(graph,visited,nbr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       int m=isConnected[0].size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j && isConnected[i][j]==1){
                     graph[i].push_back(j);
                     
                   
                }
            }
        }
    
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,visited,i);
                ans++;
            }
        }
        return ans;
    }
};