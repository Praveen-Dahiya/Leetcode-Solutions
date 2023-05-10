class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int si=0,sj=0,ei=n-1,ej=n-1;
        int t=0;
        while(t<=n*n){
           for(int j=sj;j<=ej && t<=n*n;j++){
               t++;
               ans[si][j]=t;
           } 
            if(t>=n*n) break;
            si++;
            for(int i=si;i<=ei&& t<=n*n;i++){
               t++;
               ans[i][ej]=t;
           } 
            if(t>=n*n) break;
            ej--;
            for(int j=ej;j>=sj&& t<=n*n;j--){
               t++;
               ans[ei][j]=t;
           } 
            if(t>=n*n) break;
            ei--;
            for(int i=ei;i>=si&& t<=n*n;i--){
               t++;
               ans[i][sj]=t;
           } 
             if(t>=n*n) break;
            sj++;
        }
        return ans;
        
    }
};