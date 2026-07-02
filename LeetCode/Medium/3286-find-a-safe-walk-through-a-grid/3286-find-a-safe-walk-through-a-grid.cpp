class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (cost > dist[r][c]) continue;

            if (r == m - 1 && c == n - 1) {
                return health - cost > 0;
            }

            for (auto &[dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }

        return false;
    }
};