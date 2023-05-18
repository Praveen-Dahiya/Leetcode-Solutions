//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& vis,int i,int j){
        
        if(i>=matrix.size() || i<0  || j>=matrix[0].size() || j<0){
            return;
        }
        
        if(vis[i][j]){
            return ;
        }
        if(matrix[i][j]==0){
            return ;
        }
        vis[i][j]=true;
        
        dfs(matrix,vis,i+1,j);
        dfs(matrix,vis,i-1,j);
        dfs(matrix,vis,i,j+1);
        dfs(matrix,vis,i,j-1);
        
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
       
       vector<vector<bool>> vis(N,vector<bool> (M,false));
       
       for(int i=0;i<N;i++){
           
           for(int j=0;j<M;j++){
               
               
               
              if((i==0 || j==0 || i==matrix.size()-1 || j==matrix[0].size()-1) && matrix[i][j]==1 && vis[i][j]==false){
                    dfs(matrix,vis,i,j);
              }
               
              
           }
       }
       
     
       int ans=0;
       
       for(int i=0;i<N;i++){
           
           for(int j=0;j<M;j++){
               
               if(vis[i][j]==false &&  matrix[i][j]==1){
                  
                    dfs(matrix,vis,i,j);
                  ans++;
               }
               
              
           }
       }
       
    //      for(int i=0;i<N;i++){
           
    //       for(int j=0;j<M;j++){
               
               
    //           cout<<vis[i][j]<<" ";
               
              
    //       }
    //       cout<<"\n";
    //   }
       return ans;
       
       
       
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends