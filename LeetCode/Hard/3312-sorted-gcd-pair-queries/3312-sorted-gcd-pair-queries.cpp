class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number in nums
        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: For each i, count how many numbers in nums are divisible by i
        vector<long long> count(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                count[i] += freq[j];
            }
        }
        
        // Step 3: Use Inclusion-Exclusion to find exact pairs with GCD == i
        vector<long long> gcd_count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_pairs = count[i] * (count[i] - 1) / 2;
            long long multiples_sum = 0;
            for (int j = 2 * i; j <= max_val; j += i) {
                multiples_sum += gcd_count[j];
            }
            gcd_count[i] = total_pairs - multiples_sum;
        }
        
        // Step 4: Compute prefix sums of the GCD counts
        vector<long long> prefix_sum(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + gcd_count[i];
        }
        
        // Step 5: Answer each query using binary search (upper_bound)
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first index where prefix_sum[idx] > q
            auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), q);
            ans.push_back(distance(prefix_sum.begin(), it));
        }
        
        return ans;
    }
};