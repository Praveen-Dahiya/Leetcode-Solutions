class Solution {
public:
    int minOperations(vector<int>& a) {
        map<int, int> mp;
		for (auto &x : a) {
			
			mp[x]++;
		}
        int n=a.size();
		if (mp[1] > 0) {
			return n - mp[1];
			
		}
		int ans = INT_MAX;

		for (int i = 0; i < n; i++) {

			int idx = i;
			int cans = a[i];


			while (idx >= 0 && cans > 1) {

				cans = gcd(cans, a[idx]);
				idx--;
			}
			idx++;
			if (cans == 1) {

				ans = min(ans, n - 1 + i - idx);
			}
			// cout << idx << " " << ans << "\n";
		}

		if (ans == INT_MAX) {
			return -1;
		} return ans;
    }
};