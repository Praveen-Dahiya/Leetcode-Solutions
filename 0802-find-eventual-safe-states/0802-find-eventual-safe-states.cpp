class Solution {
public:
    vector<int> ans;
    set<int> st;
    bool dfs(vector<vector<int>>& graph,int src,vector<bool> & vis,vector<bool> & currvis){
        
       vis[src]=true;
       currvis[src]=true;
        for(auto x: graph[src]){
            if(vis[x]==false){
                bool pans=dfs(graph,x,vis,currvis);
                if(pans==true){
                   st.insert(src);
                     return true;
                }
               
            }else if(vis[x]==true && currvis[x]==true){
                    st.insert(src);
                return true;
                
            }
        }
        currvis[src]=false;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<bool> visited(graph.size());
        vector<bool> currvisited(graph.size());
        
        for(int i=0;i<graph.size();i++){
            if(visited[i]==false){
                dfs(graph,i,visited,currvisited);
            }
              
        }
          for(int i=0;i<graph.size();i++){
              if(st.find(i)==st.end()){
                  ans.push_back(i);
              }
          }
        return ans;
    }
};