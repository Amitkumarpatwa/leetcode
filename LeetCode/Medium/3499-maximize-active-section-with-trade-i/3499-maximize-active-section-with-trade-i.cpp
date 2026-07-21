class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        // Augment the string as described
        string t = "1" + s + "1";

        // Compress string into segments of {character, length}
        vector<pair<char, int>> segs;
        for (char c : t) {
            if (!segs.empty() && segs.back().first == c) {
                segs.back().second++;
            } else {
                segs.push_back({c, 1});
            }
        }

        int maxDelta = 0;

        // Look for any '1' segment surrounded by two '0' segments
        for (size_t i = 1; i + 1 < segs.size(); ++i) {
            if (segs[i].first == '1' && segs[i - 1].first == '0' && segs[i + 1].first == '0') {
                int leftZeros = segs[i - 1].second;
                int rightZeros = segs[i + 1].second;
                maxDelta = max(maxDelta, leftZeros + rightZeros);
            }
        }

        return totalOnes + maxDelta;
    }
};