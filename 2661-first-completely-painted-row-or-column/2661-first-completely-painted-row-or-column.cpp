class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> row(mat.size()),col(mat[0].size());
        
        map<int,pair<int,int> > mp;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                
                mp[mat[i][j]]={i,j};
            }
        }
      
        for(int i=0;i<arr.size();i++){
            
            int x=mp[arr[i]].first;
            int y=mp[arr[i]].second;
            
            row[x]++;
            col[y]++;
           
            if(row[x]==mat[0].size()){
                return i;
            }
            if(col[y]==mat.size()){
                return i;
            }
            
        
        }
        return 0;
    }
};