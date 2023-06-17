class Solution {
public:
    int dp[2001][2002][2];
    int rec(vector<int>& arr1, vector<int>& arr2,int idx,int prev,int of){
        
        if(idx>=arr1.size()) return 0;
        int f1=2001;
        int f2=2001;
        
        if(dp[idx][prev+1][of] !=-1){
            return dp[idx][prev+1][of];
        }
        if(prev==-1){
            f1=rec(arr1,arr2,idx+1,idx,0);
            f2=1+rec(arr1,arr2,idx+1,idx,1);
        }else{
            
            
            if(of==0){
                 auto ub = std::upper_bound(arr2.begin(), arr2.end(), arr1[prev])-arr2.begin();
                if(ub!=arr2.size()){
                    f1=1+rec(arr1,arr2,idx+1,ub,1);
                }
                if(arr1[idx]>arr1[prev]){
                     f2=rec(arr1,arr2,idx+1,idx,0);
                }
            }else{
                
                 auto ub = std::upper_bound(arr2.begin(), arr2.end(), arr2[prev])-arr2.begin();
                if(ub!=arr2.size()){
                    f1=1+rec(arr1,arr2,idx+1,ub,1);
                }
                if(arr1[idx]>arr2[prev]){
                     f2=rec(arr1,arr2,idx+1,idx,0);
                }
            }
           
        }
        return dp[idx][prev+1][of]=min(f1,f2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof(dp));
        int x=rec(arr1,arr2,0,-1,1);
        if(x>arr1.size()){
            return -1;
        }
        return x;
    }
};