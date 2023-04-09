class Solution {
public:
     map<int, vector<int>> adj;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        
        vector<int> indegree(N, 0);
        
        for(auto &vec : edges) {
    
            adj[ vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
            
        }
        
        queue<int> q;
        vector<vector<int>> t(N, vector<int>(26, 0));
        
        for(int i = 0; i<N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                
                t[i][colors[i]-'a'] = 1;
            }
        }
        
        int ans = 0;
        int cn = 0;
        
        while(q.size()>0) {
            
            auto u = q.front();
            q.pop();
            
            cn++;
            
            ans = max(ans, t[u][colors[u]-'a']);
            
            for(int &v : adj[u]) {
                
                for(int i = 0; i<26; i++) {
                    
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v]-'a' == i));
                    
                }
                
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
            
        }
        
        if(cn < N)
            return -1;
        
        return ans;
    }
};