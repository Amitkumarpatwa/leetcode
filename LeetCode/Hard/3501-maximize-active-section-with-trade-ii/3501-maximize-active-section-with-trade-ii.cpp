class SparseTable {
private:
    int n;
    vector<vector<int>> st;

public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        
        int log = 32 - __builtin_clz(n);
        st.assign(log, vector<int>(n));
        
        st[0] = nums;
        for (int i = 1; i < log; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r || n == 0) return 0;
        int i = 32 - __builtin_clz(r - l + 1) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

struct Group {
    int start;
    int length;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIndex[i] = zeroGroups.size() - 1;
        }

        int m = zeroGroups.size();
        vector<int> ans;
        ans.reserve(queries.size());

        if (m == 0) {
            return vector<int>(queries.size(), totalOnes);
        }

        // Precompute adjacent zero group length sums
        vector<int> adjacentSums(m - 1, 0);
        for (int i = 0; i < m - 1; ++i) {
            adjacentSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }

        SparseTable st(adjacentSums);

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int leftLen = (s[l] == '0') ? zeroGroups[zeroGroupIndex[l]].length - (l - zeroGroups[zeroGroupIndex[l]].start) : -1;
            int rightLen = (s[r] == '0') ? (r - zeroGroups[zeroGroupIndex[r]].start + 1) : -1;

            int startAdjacentIdx = zeroGroupIndex[l] + 1;
            int endAdjacentIdx = (s[r] == '1') ? zeroGroupIndex[r] - 1 : zeroGroupIndex[r] - 2;

            int maxGained = 0;

            // Case 1: Trade within adjacent partial boundaries
            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                maxGained = max(maxGained, leftLen + rightLen);
            }

            // Case 2: Full adjacent groups inside the inner range
            if (startAdjacentIdx <= endAdjacentIdx) {
                maxGained = max(maxGained, st.query(startAdjacentIdx, endAdjacentIdx));
            }

            // Case 3: Partial left + next full group
            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) {
                maxGained = max(maxGained, leftLen + zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            // Case 4: Previous full group + partial right
            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
                maxGained = max(maxGained, rightLen + zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(totalOnes + maxGained);
        }

        return ans;
    }
};