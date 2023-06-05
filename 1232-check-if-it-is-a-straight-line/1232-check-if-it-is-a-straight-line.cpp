class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      map<long double,int> mp;
        int f=0;
         int n=coordinates.size();
      for(int i=0;i<n;i++){
          
          for(int j=i+1;j<n;j++){
              int x1=coordinates[i][0];
              int y1=coordinates[i][1];
              int x2=coordinates[j][0];
              int y2=coordinates[j][1];
              
              if(x1-x2 ==0){
                  f++;
              }else{
                  mp[(y1-y2)/(x1-x2)]++;
              }
          }
      }
       // cout<<f<<"\n";
        if(f==(n*(n-1))/2){
            return true;
        }
        if(f>0) return false;
        
        if(mp.size()==1) return true;
        return false;
    }
};