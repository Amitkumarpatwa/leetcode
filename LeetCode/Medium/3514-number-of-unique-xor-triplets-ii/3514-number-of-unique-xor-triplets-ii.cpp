class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        // Step 1: Extract unique values from nums
        std::vector<int> unique_nums;
        std::vector<bool> seen(2048, false);
        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                unique_nums.push_back(x);
            }
        }

        // Step 2: Precompute all unique pair XOR results
        std::vector<bool> v2(2048, false);
        for (size_t i = 0; i < unique_nums.size(); ++i) {
            for (size_t j = i; j < unique_nums.size(); ++j) {
                v2[unique_nums[i] ^ unique_nums[j]] = true;
            }
        }

        // Step 3: Compute all unique triplet XOR results
        std::vector<bool> v3(2048, false);
        for (int p = 0; p < 2048; ++p) {
            if (v2[p]) {
                for (int x : unique_nums) {
                    v3[p ^ x] = true;
                }
            }
        }

        // Step 4: Count unique triplet XOR values
        int count = 0;
        for (int i = 0; i < 2048; ++i) {
            if (v3[i]) {
                count++;
            }
        }

        return count;
    }
};