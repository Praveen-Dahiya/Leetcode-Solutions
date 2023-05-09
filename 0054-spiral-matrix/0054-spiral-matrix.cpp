class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        vector<int> ans;
    int sc=0;
    int sr=0;
    int ec=A[0].size()-1;
    int er=A.size()-1;
    int total =A.size()*A[0].size();
    int c=0;
    while(sr<=er && sc<=ec){

        for(int j=sc;j<=ec;j++){
            if(total ==c) return ans;
            ans.push_back(A[sr][j]);
            c++;
        }
        sr++;
        for(int i=sr;i<=er;i++){
              if(total ==c) return ans;
            ans.push_back(A[i][ec]);
            c++;
        }
        ec--;
        if(er >= sr){
         for(int j=ec;j>=sc;j--){
               if(total ==c) return ans;
            ans.push_back(A[er][j]);
            c++;
        }
        er--;
        }
        if(ec>=sc){
        for(int i=er;i>=sr;i--){
              if(total ==c) return ans;
            ans.push_back(A[i][sc]);
            c++;
        }
        sc++;
        }
  

    }
    return ans;
    }
};