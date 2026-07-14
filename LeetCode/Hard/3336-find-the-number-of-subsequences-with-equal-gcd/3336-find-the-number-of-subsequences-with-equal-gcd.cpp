class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // dp[g1][g2] stores the number of valid pairs of subsequences
        // State 0 represents an empty subsequence (since gcd(0, x) = x)
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1; // Base case: both subsequences are empty

        for (int num : nums) {
            vector<vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    // Option 1: Add num to the first subsequence
                    int n_g1 = (g1 == 0) ? num : std::gcd(g1, num);
                    next_dp[n_g1][g2] = (next_dp[n_g1][g2] + dp[g1][g2]) % MOD;

                    // Option 2: Add num to the second subsequence
                    int n_g2 = (g2 == 0) ? num : std::gcd(g2, num);
                    next_dp[g1][n_g2] = (next_dp[g1][n_g2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        // Sum up all states where g1 == g2 and both are non-empty (g1 > 0)
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};