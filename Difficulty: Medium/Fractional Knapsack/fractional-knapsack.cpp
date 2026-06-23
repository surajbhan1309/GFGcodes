class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratio(n);
        
        for (int i = 0; i < n; i++) {
            ratio[i] = {(double)val[i] / wt[i], i};
        }
        
        sort(ratio.rbegin(), ratio.rend());
        
        double max_value = 0.0;
        int current_weight = 0;
        
        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            
            if (current_weight + wt[idx] <= capacity) {
                current_weight += wt[idx];
                max_value += val[idx];
            } 
            else {
                int remaining_capacity = capacity - current_weight;
                max_value += ratio[i].first * remaining_capacity;
                break;
            }
        }
        
        return max_value;
    }
};