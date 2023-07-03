class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length()!=goal.length()){
            return false;
        }
        int c=0;
        map<char,int> mp1,mp2;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]) c++;
            mp1[s[i]]++,mp2[goal[i]]++;
        }
        if(mp1 !=mp2){
            return false;
        }
        if(c>2) return false;
        if(c==2) return true;
        if(c==1 && mp1.size()!=s.length()){
            return true;
        }
        if(c==0 && mp1.size()!=s.length()){
            return true;
        }
        return false;
    }
};