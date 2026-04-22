class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = arr[(i + d) % n];
        }
        
        arr=nums;
    }
};