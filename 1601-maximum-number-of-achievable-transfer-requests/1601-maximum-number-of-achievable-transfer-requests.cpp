class Solution {
public:
    int ans;
     vector<int> in;
    void rec(int n, vector<vector<int>>& requests ,int mask,int idx,int cans){
        
        if(idx>=requests.size()){
            
           
           int x=0;
            while(mask>0){
                if(mask&1) x++;
                
                mask/=2;
            }
            bool update=true;
            
            for(int i=0;i<n;i++){
                if(in[i]!=0) {
                    update=false;
                }
            }
            
            if(update){
                ans=max(ans,x);                
            }

            return;
        }
        in[requests[idx][1]]--;
        in[requests[idx][0]]++;
        rec(n,requests,mask|(1<<idx),idx+1,cans);
        in[requests[idx][1]]++;
        in[requests[idx][0]]--;
        
        rec(n,requests,mask,idx+1,cans);
        
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        in.resize(n);
        ans=0;
        
        rec(n,requests,0,0,0);
        return ans;
        
        
    }
};