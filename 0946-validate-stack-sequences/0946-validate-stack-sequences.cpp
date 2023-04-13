class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int idx=0;
        
        stack<int> st;
        int n=pushed.size();
        
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            
            
            while(st.size()>0 && st.top()==popped[idx]){
                st.pop();
                idx++;
            }
        }
        
        return idx==n;
    }
};