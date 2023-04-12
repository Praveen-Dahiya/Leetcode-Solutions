class Solution {
public:
    string simplifyPath(string path) {
     
        stringstream ss(path);
        
        vector<string> tokenized, ans;
        string s;
        while(getline(ss, s, '/')){
            tokenized.push_back(s);
        } 
        
        for(auto i:tokenized){
            if(i==".." && ans.size()){
                 ans.pop_back();
            }else if(i!="." && i!="" && i!=".."){
                ans.push_back(i);
            } 
        }
        
       
        
        string fans = "/";
        for(auto i:ans){
            fans += i + "/";
        }
        if(fans.size()>1){
            fans.pop_back();
        }
        return fans;
    }
};