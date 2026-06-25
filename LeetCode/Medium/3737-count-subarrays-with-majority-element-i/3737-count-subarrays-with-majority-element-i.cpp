class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = 0;

        for(int start = 0; start < n; start++) {

            int cnt = 0;

            for(int end = start; end < n; end++) {

                if(nums[end] == target)
                    cnt++;

                int len = end - start + 1;

                if(cnt > len / 2)
                    ans++;
            }
        }

        return ans;
    }
};