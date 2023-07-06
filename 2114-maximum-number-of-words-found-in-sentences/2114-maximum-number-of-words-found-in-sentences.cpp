class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        
        for(int i=0;i<sentences.size();i++){
            
            string cur="";
            
            int cans=0;
            
            for(auto &x:sentences[i]){
                if(x==' '){
                    cur="";
                    cans++;
                }else{
                   cur+=x; 
                    
                } 
                
            }
            if(cur.size()>0) cans++;
            
            ans=max(ans,cans);
        }
        return ans;
    }
};