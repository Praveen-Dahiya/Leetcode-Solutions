class Solution {
public:
    vector<string> ans;
    void rec(string &s,  set<string> &st,string pans,int idx){
        
        if(idx>=s.length()){
            // cout<<pans<<" ";
            ans.push_back(pans);
            return;
        }
        string w="";
        for(int i=idx;i<s.length();i++){
            
            w+=s[i];
            if(st.find(w)!=st.end()){
                // cout<<w<<" ";
                if(pans.size()>0){
                     rec(s,st,pans+" "+w,i+1);
                }else{
                     rec(s,st,w,i+1);
                }
               
            }
        }
        
        
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        
        for(auto &x:wordDict){
            st.insert(x);
        }
        rec(s,st,"",0);
        
        return ans;
        
        
        
        
    }
};