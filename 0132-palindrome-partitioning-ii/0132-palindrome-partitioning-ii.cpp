class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            // If s[0...i] itself is a palindrome,
            // no cut is required.
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i;  // Maximum possible cuts

                for (int j = 1; j <= i; j++) {
                    // s[j...i] is a palindrome
                    if (pal[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};