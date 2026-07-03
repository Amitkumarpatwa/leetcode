class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
       int n = online.size(); // Fixed: changed .length() to .size()
        int max_cost = -1;
        for (const auto& edge : edges) {
            max_cost = max(max_cost, edge[2]);
        }

        // Helper lambda to check if a path with minimum edge cost >= mid exists within budget k
        auto isValid = [&](int mid) -> bool {
            // Build adjacency list for valid components
            vector<vector<pair<int, int>>> adj(n);
            vector<int> inDegree(n, 0);

            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], cost = edge[2];
                
                // Only consider edges with cost >= mid
                if (cost < mid) continue;
                
                // Only consider paths through online intermediate nodes
                if (u != 0 && !online[u]) continue;
                if (v != n - 1 && !online[v]) continue;

                adj[u].push_back({v, cost});
                inDegree[v]++;
            }

            // Kahn's algorithm for Topological Sort to find shortest path in DAG
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (inDegree[i] == 0) q.push(i);
            }

            // minDist[i] stores the minimum total cost to reach node i from node 0
            // Using a value larger than k to represent infinity
            long long INF = k + 1;
            vector<long long> minDist(n, INF);
            minDist[0] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int cost = neighbor.second;

                    if (minDist[u] != INF && minDist[u] + cost < minDist[v]) {
                        minDist[v] = minDist[u] + cost;
                    }

                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        q.push(v);
                    }
                }
            }

            return minDist[n - 1] <= k;
        };

        // Binary search for the maximum possible minimum-edge-cost
        int low = 0, high = max_cost, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans = mid;       // mid is possible, try to find a larger minimum edge cost
                low = mid + 1;
            } else {
                high = mid - 1;  // mid is too restrictive, lower the required edge cost
            }
        }

        return ans; 
    }
};