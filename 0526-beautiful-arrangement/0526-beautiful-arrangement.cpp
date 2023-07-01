class Solution {
public:
    int ans=0;
    int rec(int n,int mask,int idx){
       
        if(idx>=n){
            ans++;
            return 1;
        }
        
        int ans=1;
        
        for(int i=1;i<=n;i++){
             
            if(((idx+1)%i)==0 || (i%(idx+1))==0){
                
                if(( mask &(1<<(i-1)))==0){
                    ans*=rec(n,mask|(1<<(i-1)),idx+1);
                }
            }
        }
        return ans;
        
        
    }
    int countArrangement(int n) {
        rec(n,0,0);
        return ans;
    }
};