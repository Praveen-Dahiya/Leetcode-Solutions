class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int i=0,j=0;
        while(i<mat.size()&&j<mat.size()){
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=0,j=mat.size()-1;
          while(i<mat.size()&&j>=0){
               sum+=mat[i][j];
              i++;
              j--;
          }
        if(mat.size()%2){
            sum-=mat[mat.size()/2][mat.size()/2];
        }
        return sum;
    }
};