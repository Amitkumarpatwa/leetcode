class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2) {
            return n;
        }
        
        int bit_width = 0;
        while ((1 << bit_width) <= n) {
            bit_width++;
        }
        
        return 1 << bit_width;
    }
};