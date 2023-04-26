class Solution {
public:
    int addDigits(int num) {
       
        int ans=num;
        
        while(ans>=10){
            
            int ans2=0;
            while(ans>0){
                ans2+=(ans%10);
                ans/=10;
            }
            ans=ans2;
            cout<<ans<<" ";
        }
        return ans;
    }
};