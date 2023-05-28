class Solution {
public:
    int t[103][103];
    int solve(vector<int>& cuts, int l, int r) {
        
        if(r - l == 1){
            return 0;// no cuts
        }
            
        
        if(t[l][r] != -1){
            return t[l][r];
        }
            
        
        int result = INT_MAX;
        
        for(int index = l+1; index <= r-1; index++) {
            
            int cost = solve(cuts, l, index) + solve(cuts, index, r) + (cuts[r] - cuts[l]);
            
            result = min(result, cost);
            
        }
        
        return t[l][r] = result;
        
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        memset(t, -1, sizeof(t));
        return solve(cuts, 0, cuts.size()-1);
    }
};