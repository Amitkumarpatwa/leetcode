class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;

        if (freq.count(1)) {
            ans = freq[1];
            if (ans % 2 == 0) ans--;
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1) continue;

            long long x = num;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len += 2;
                x = x * x;
            }

            if (freq.count(x))
                len += 1;
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};