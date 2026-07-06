class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];   // larger end first
                return a[0] < b[0];
            });

        int ans = 0;
        int maxEnd = 0;

        for (auto &in : intervals) {
            if (in[1] > maxEnd) {
                ans++;
                maxEnd = in[1];
            }
        }

        return ans;
    }
};