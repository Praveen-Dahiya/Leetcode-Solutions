class Solution {
public:
    int minMaxDifference(int num) {
        
        string s=to_string(num);
        int idx1=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='9'){
                idx1=i;
                break;
            }
        }
        
        int idx2=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                idx2=i;
                break;
            }
        }
        string s1=s;
        if(idx1 !=-1){
            
            for(int i=0;i<s1.length();i++){
                if(s1[i]==s[idx1]){
                    s1[i]='9';
                }
            }
        }
        string s2=s;
        if(idx2 !=-1){
            
            for(int i=0;i<s2.length();i++){
                if(s2[i]==s[idx2]){
                    s2[i]='0';
                }
            }
        }
        int ans=stoi(s1)-stoi(s2);
        // cout<<s1<<" "<<s2<<"\n";
        return ans;
    }
};