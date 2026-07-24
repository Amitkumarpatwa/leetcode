class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        int minDiff = INT_MAX;
        
        // Step 2: Compare adjacent elements only
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            
            if (diff < minDiff) {
                minDiff = diff;
                ans.clear(); // Found a new smaller difference, discard previous pairs
                ans.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return ans;
    }
};