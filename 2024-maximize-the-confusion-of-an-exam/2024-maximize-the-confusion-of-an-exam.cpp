class Solution {
public:
    int longestOnes(string answerKey, int k,char ch) {
      
        int n=answerKey.length();
        int sp=-1;
        int ep=-1;
        
        int zeroes=0;
        int ans=0;
        while(1){
            bool f1=false,f2=false;
            while(ep<n-1){
                f1=true;
                if(zeroes==k && answerKey[ep+1]==ch) break;
                
                ep++;
                if(answerKey[ep]==ch){
                    zeroes++;
                }
                
            }
            
            
            ans=max(ans,ep-sp);
            while(sp<n-1 && zeroes==k){
                f2=true;
                sp++;
                if(answerKey[sp]==ch){
                    zeroes--;
                }
                
            }
            if(!f1 &&!f2) break;
            // cout<<sp<<" "<<ep<<" "<<ans<<"\n";
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestOnes(answerKey,k,'T'),longestOnes(answerKey,k,'F'));
    }
};