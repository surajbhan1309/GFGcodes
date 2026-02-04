class Solution {
  public:
    string findOrder(vector<string> &words) {
        int N = words.size();
        
        // Step 1: Collect all unique characters
        unordered_map<char, int> mp;
        int idx = 0;
        for (auto &w : words) {
            for (char c : w) {
                if (mp.find(c) == mp.end())
                    mp[c] = idx++;
            }
        }

        int K = idx;  // total unique characters
        
        // Step 2: Build graph
        vector<vector<int>> adj(K);
        vector<int> indegree(K, 0);

        for (int i = 0; i < N - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = mp[w1[j]];
                    int v = mp[w2[j]];
                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix problem
            if (!found && w1.size() > w2.size())
                return "";
        }

        // Step 3: Kahn’s Algorithm
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        string order = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order += (char)(find_if(mp.begin(), mp.end(),
                         [&](auto &p) { return p.second == u; })->first);

            for (int v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 4: Cycle check
        if (order.size() != K)
            return "";

        return order;
    }
};
