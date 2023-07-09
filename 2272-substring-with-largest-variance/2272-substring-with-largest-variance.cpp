class Solution {
public:
    int largestVariance(string s) {
        vector<int> mp(26, 0);
        
        for(char &ch : s) {
            mp[ch-'a']++;
        }
        
        int ans = 0;

        for (char first = 'a'; first <= 'z'; ++first) {

            for (char second = 'a'; second <= 'z'; ++second) {

                // if (mp[first-'a'] == 0 || mp[second-'a'] == 0) 
                //     continue;

                int fC = 0;
                int sC = 0;
                bool seen = false;

                for (const char& ch : s) {
                    if (ch == first) ++fC;
                    if (ch == second) ++sC;

                    if (sC > 0) {
                        ans = max(ans, fC - sC);
                    } else if (seen) {
                        ans = max(ans, fC - 1);
                    } 

                    if (sC > fC) {
                        sC = 0;
                        fC = 0;
                        seen = true;
                    }
                }
            }
        }
        return ans;

    }
};