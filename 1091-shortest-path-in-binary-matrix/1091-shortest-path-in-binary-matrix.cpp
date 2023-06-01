class Solution {
public:
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int> > q;
       vector<vector<bool> > visited(n,vector<bool> (n,false));
        if(grid[0][0]==1) return -1;
        q.push({0,0});
    int ans=0;
        while(q.size()>0){
            int s=q.size();
            ans++;
            while(s-- >0){
                auto rem=q.front();
                q.pop();
                //cout<<rem.first<<" "<<rem.second<<endl;;
                if(rem.first==n-1 && rem.second==n-1){return ans;}
                visited[rem.first][rem.second]=true;
                for(int i=0;i<8;i++){
                    int nr=rem.first+dirs[i][0];
                    int nc=rem.second+dirs[i][1];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                         q.push({nr,nc});
                        grid[nr][nc]=1;
                    }
                   
                }
                
            }
           
            
            
        }
        return -1;
        
    }
};