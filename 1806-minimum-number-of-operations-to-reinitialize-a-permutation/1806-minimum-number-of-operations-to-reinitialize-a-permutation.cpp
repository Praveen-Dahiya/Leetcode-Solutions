class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> check(n);
        for(int i=0;i<n;i++){
            check[i]=i;
        }
        vector<int> change=check;
        
        int ans=0;
        
        while(1){
             vector<int> t(n);
            for(int i=0;i<n;i++){
                if(i%2){
                    t[i]=change[(n/2)+(i-1)/2];
                }else{
                    t[i]=change[i/2];
                }
            }
            ans++;
            change=t;
            if(check==change){
                break;
            }
            
        }
        return ans;
    }
};