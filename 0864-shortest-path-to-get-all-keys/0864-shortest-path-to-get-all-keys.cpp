class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q;
        int c = 0;
        for(int i = 0; i<m; i++) {
            
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == '@') {
                    q.push({i, j, 0, 0});
                } else if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    c++;
                }
                
            }
        }
        int finalBitmask = pow(2, c) - 1;
        
        
        int vis[m][n][finalBitmask+1];
        memset(vis, 0, sizeof(vis));
        
        while(q.size()>0) {
            
            auto rem = q.front();
            q.pop();
            
            int i = rem[0];
            int j = rem[1];
            int steps = rem[2];
            int currentBitmask = rem[3];
            
            if(currentBitmask == finalBitmask) {
                return steps;
            }
            if(vis[i][j][currentBitmask]==1) continue;
            vis[i][j][currentBitmask]=1;
            for(vector<int> & dir : directions) {
                
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if(ni >= 0 && ni < m && nj >= 0 && nj < n  && grid[ni][nj]!='#') {
                    char ch = grid[ni][nj];
                        
                    if(ch >= 'A' && ch <= 'F') { 
                        
                        if(vis[ni][nj][currentBitmask] == 0 && ((currentBitmask >> (ch-'A')) & 1) == 1) {
                            q.push({ni, nj, steps+1, currentBitmask});
                        }
                        
                    } else if(ch >= 'a' && ch <= 'f') {
                        
                        int newBitmask = currentBitmask | (1 << (ch - 'a'));
                        
                        if(vis[ni][nj][newBitmask] == 0) {
                            q.push({ni, nj, steps+1, newBitmask});
                        }
                        
                    } else {
                        if(vis[ni][nj][currentBitmask] == 0) {
                            q.push({ni, nj, steps+1, currentBitmask});
                        }
                    }
                    
                }
                
            }
            
        }
        
        return -1;
    }
};