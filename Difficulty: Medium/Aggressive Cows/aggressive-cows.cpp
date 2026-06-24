class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canplace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    bool canplace(vector<int> &stalls, int k, int dist) {
        int cows = 1;
        int lastpos = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastpos >= dist) {
                cows++;
                lastpos = stalls[i];
            }
        }
        return cows >= k;
    }
};
