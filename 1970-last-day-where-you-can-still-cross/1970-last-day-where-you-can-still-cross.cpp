class Solution {
public:
    vector<vector<int> > dirs={{-1,0},{0,-1,},{0,1},{1,0}};
    bool canDo(int row,int col, vector<vector<int>>& cells,int mi){
        
         vector<vector<int>> arr(row,vector<int> (col,0));
        for(int i=0;i<mi;i++){
            int x=cells[i][0];
            int y=cells[i][1];
            arr[x-1][y-1]=1;
        }
        
        vector<vector<bool>> vis(row,vector<bool> (col,false));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<col;i++){
            if(arr[0][i]==0){
                q.push({0,i});
            }
        }
        
        while(q.size()>0){
            
            auto rem=q.front();
            q.pop();
            if(vis[rem.first][rem.second]){
                continue;
            }
            vis[rem.first][rem.second]=true;
            
            
            if(rem.first==(row-1)){
                return true;
            }
            
            for(auto &dir:dirs){
                
                int ni=dir[0]+rem.first;
                int nj=dir[1]+rem.second;
                
                if(ni>=0 && nj>=0 && ni<row && nj <col && vis[ni][nj]==false && arr[ni][nj]==0){
                    q.push({ni,nj});
                }
            }
        }
        return false;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int ans=0;
        
        int si=0;
        int ei=row*col;
        
        while(si<=ei){
            int mi=(si+ei)/2;
            
            if(canDo(row,col,cells,mi)){
                ans=mi;
                si=mi+1;
            }else{
                ei=mi-1;
                
            }
        }
        return ans;
    }
};