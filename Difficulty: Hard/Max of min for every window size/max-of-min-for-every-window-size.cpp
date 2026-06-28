class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> left(n), right(n);
        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && arr[dq.back()] >= arr[i]) {
                dq.pop_back();
            }
            left[i] = dq.empty() ? -1 : dq.back();
            dq.push_back(i);
        }

        dq.clear();

        for (int i = n - 1; i >= 0; --i) {
            while (!dq.empty() && arr[dq.back()] >= arr[i]) {
                dq.pop_back();
            }
            right[i] = dq.empty() ? n : dq.back();
            dq.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

// class Solution {
// private:
//     // this solution gives time limit exceed
//     vector<int> minSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;
//         vector<int> ans;
//         for(int i=0; i<nums.size(); i++){
//             if(!dq.empty() && dq.front() <= i-k){
//                 dq.pop_front();
//             }
//             while(!dq.empty() && nums[dq.back()] >= nums[i]){ 
//                 dq.pop_back();
//             }
//             dq.push_back(i); 
//             if(i >= k-1){
//                 ans.push_back(nums[dq.front()]);
//             }
//         }
//         return ans;
//     }

// public:
//     vector<int> maxOfMins(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> result;
//         for(int k = 1; k <= n; k++) {
//             vector<int> mins = minSlidingWindow(arr, k);
//             int maxOfMin = *max_element(mins.begin(), mins.end());
//             result.push_back(maxOfMin);
//         }
//         return result;
//     }
// };
