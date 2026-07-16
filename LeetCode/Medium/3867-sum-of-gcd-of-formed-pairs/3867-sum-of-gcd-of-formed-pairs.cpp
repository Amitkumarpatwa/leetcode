class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        
        // Sort in non-decreasing order
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long totalGcdSum = 0;
        int left = 0, right = n - 1;
        
        // Form pairs by picking the smallest and largest unpaired elements
        while (left < right) {
            totalGcdSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalGcdSum;
    }
};