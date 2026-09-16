class Solution {
public:
    int getKey(int x) {
        int key = 1;

        for (int p = 2; p * p <= x; p++) {
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            if (cnt % 2 == 1) {
                key *= p;
            }
        }

        if (x > 1) {
            key *= x;
        }

        return key;
    }

    long long dfs(int node, int parent,
                  vector<vector<int>>& graph,
                  vector<int>& key,
                  unordered_map<int, int>& freq) {

        long long ans = 0;

        // Ancestors having the same square-free key
        ans += freq[key[node]];

        // Add current node to ancestor set
        freq[key[node]]++;

        for (int next : graph[node]) {
            if (next != parent) {
                ans += dfs(next, node, graph, key, freq);
            }
        }

        // Remove current node before going back
        freq[key[node]]--;

        return ans;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges,
                             vector<int>& nums) {

        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Convert every number to its square-free form
        vector<int> key(n);

        for (int i = 0; i < n; i++) {
            key[i] = getKey(nums[i]);
        }

        unordered_map<int, int> freq;

        return dfs(0, -1, graph, key, freq);
    }
};