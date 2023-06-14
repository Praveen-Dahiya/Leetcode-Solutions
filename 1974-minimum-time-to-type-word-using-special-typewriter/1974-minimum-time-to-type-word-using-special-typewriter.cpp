class Solution {
public:
    int minTimeToType(string word) {
        int ans=word.length();
        char prev='a';
        for(int i=0;i<word.length();i++){
            
            int add1=(word[i]-prev +26)%26;
              int add2=(-word[i]+prev +26)%26;
            // cout<<add1<<" "<<add2<<"\n";
            ans+=(min(add1,add2));
            
            prev=word[i];
            
        }
        return ans;
    }
};