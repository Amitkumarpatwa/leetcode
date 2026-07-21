class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int zero = 0, len = 0;

        while (r < n) {
            // Include nums[r] in the window
            if (nums[r] == 0)
                zero++;

            // Shrink the window until it becomes valid
            while (zero > k) {
                if (nums[l] == 0)
                    zero--;
                l++;
            }

            // Update the maximum length
            len = max(len, r - l + 1);

            r++;
        }

        return len;
    }
};