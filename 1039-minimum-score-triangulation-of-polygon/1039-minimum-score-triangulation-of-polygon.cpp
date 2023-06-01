class Solution {
public:
    int dp[501][501];


int rec(vector<int> &a, int si, int ei) {

	if (ei - si <= 1) return 0;

	if (ei - si == 2) return a[si] * a[si + 1] * a[si + 2];
	int f1 = INT_MAX;
	if (dp[si][ei] != -1) {
		return dp[si][ei];
	}
	for (int i = si + 1; i < ei; i++) {
		int ansf1 = a[si] * a[i] * a[ei] + rec(a, si, i) + rec(a, i, ei);
		f1 = min(f1, ansf1);
	}
	return dp[si][ei] = f1;
}
    int minScoreTriangulation(vector<int>& values) {
        memset(dp, -1, sizeof(dp));
		return rec(values, 0, values.size() - 1) ;
    }
};