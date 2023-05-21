class Solution {
public:
    class Pair {
public:
  int x;
  int y;
  Pair(int x, int y){
    this->x = x;
    this->y = y;
  }
};

vector<vector<int> > dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(queue<Pair>& q, int sr, int sc, vector<vector<bool>>& vis, vector<vector<int>>& mat){
  vis[sr][sc] = true;
  q.push(Pair(sr, sc));
  for (int i = 0; i < 4; ++i){
    int nrow = sr + dirs[i][0];
    int ncol = sc + dirs[i][1];
    if (nrow<0 || ncol<0 || nrow >= mat.size() || ncol >= mat[0].size() ||mat[nrow][ncol] == 0 ||vis[nrow][ncol]==true){
        continue;
    } 
   dfs(q, nrow, ncol, vis, mat);
  }

}
    int shortestBridge(vector<vector<int>>& mat) {
        queue<Pair> q;
  bool flag = false;
  vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size()));
  for (int i = 0; i < mat.size() && !flag; ++i){
    for (int j = 0; j < mat[0].size()&& !flag; ++j){
      if (mat[i][j] == 1) {
        flag = true;
        dfs(q, i, j, vis, mat);
      }
    }
  }
  int level = 0;
  while (q.size() > 0){
      
    int size = q.size();
    while (size-- >0){
      Pair rem = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i){
        int nrow = rem.x + dirs[i][0];
        int ncol = rem.y + dirs[i][1];
        if (nrow<0 || ncol<0 || nrow >= mat.size() || ncol >= mat[0].size() || vis[nrow][ncol]==true) {
            continue;
        }
        if (mat[nrow][ncol]){
            return level;
        }
        
        vis[nrow][ncol] = true;
        q.push(Pair(nrow, ncol));
      }
    }
    level++;
  }
  return -1;
 
    }
};