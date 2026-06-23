class Solution {
  public:
    int find_slot(int val, vector<int> &parent) {
        if (val == parent[val]) {
            return val;
        }
        return parent[val] = find_slot(parent[val], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs(n);
        int max_deadline = 0;
        
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
            if (deadline[i] > max_deadline) {
                max_deadline = deadline[i];
            }
        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        vector<int> parent(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++) {
            parent[i] = i;
        }
        
        int count_jobs = 0;
        int total_profit = 0;
        
        for (int i = 0; i < n; i++) {
            int curr_profit = jobs[i].first;
            int curr_deadline = jobs[i].second;
            int available_slot = find_slot(curr_deadline, parent);
            
            if (available_slot > 0) {
                parent[available_slot] = find_slot(available_slot - 1, parent);
                count_jobs++;
                total_profit += curr_profit;
            }
        }
        
        return {count_jobs, total_profit};
    }
};
