class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int x = 0;

        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            x ^= (i + 1);
        }
        return x ^ n;
    }
};