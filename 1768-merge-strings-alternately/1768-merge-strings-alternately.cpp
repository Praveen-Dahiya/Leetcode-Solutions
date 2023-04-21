class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        
        for(int i=0;i<500;i++){
            
            ans+=" ";
        }
        
        for(int i=0;i<word1.size();i++){
            
            ans[2*i]=word1[i];
        }
        
        for(int i=0;i<word2.size();i++){
            ans[2*i+1]=word2[i];
        }
        // cout<<ans<<"\n";
        string fans="";
        
        for(int i=0;i<ans.size();i++){
            
            if(ans[i]!=' '){
                fans+=ans[i];
            }
        }
        return fans;
    }
};