class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        map<char,int> mp;
        set<char> st;
        
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int curans=0;
        for(int i=0;i<k;i++){
            if(st.find(s[i])!=st.end()){
               curans++;
            }
            
        }

        ans=max(ans,curans);
        for(int i=k;i<s.length();i++){
            
            if(st.find(s[i-k])!=st.end()){
                 curans--;
            }
            if(st.find(s[i])!=st.end()){
               curans++;
            }

            ans=max(ans,curans);
        }
        return ans;
    }
};