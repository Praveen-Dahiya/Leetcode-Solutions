class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        
        int pans=0;
        set<int> s1,s2;
        for(int i=0;i<A.size();i++){
            
            
            s1.insert(A[i]);
            s2.insert(B[i]);
            
            if(A[i]==B[i]){
                pans++;
                 ans.push_back(pans);
                continue;
            }
            
            if(s1.find(B[i])!=s1.end()){
                pans++;
            }
            if(s2.find(A[i])!=s2.end()){
                pans++;
            }
            ans.push_back(pans);
        }
        return ans;
    }
};