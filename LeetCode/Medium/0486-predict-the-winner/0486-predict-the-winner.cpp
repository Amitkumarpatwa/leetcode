class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores the max score difference the current player can get from nums[i...j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Base case: Subarrays of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill DP table for subarray lengths from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], 
                                    nums[j] - dp[i][j - 1]);
            }
        }

        // Player 1 wins if final score difference >= 0
        return dp[0][n - 1] >= 0;
    }
};