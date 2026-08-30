class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniPos = 0;
        int maxiPos = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                miniPos = i;
            }

            if (nums[i] > maxi) {
                maxi = nums[i];
                maxiPos = i;
            }
        }

        int first = min(miniPos, maxiPos);
        int last = max(miniPos, maxiPos);

        int bothLeft = last + 1;
        int bothRight = n - first;
        int oneLeftOneRight = first + 1 + n - last;

        return min({bothLeft, bothRight, oneLeftOneRight});
    }
};