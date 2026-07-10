class Solution {
private:
    int atMostK(vector<int> &arr, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> countMap;
        int left = 0;
        int totalSubarrays = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            countMap[arr[right]]++;
            
            while (countMap.size() > k) {
                countMap[arr[left]]--;
                if (countMap[arr[left]] == 0) {
                    countMap.erase(arr[left]);
                }
                left++;
            }
            
            totalSubarrays += (right - left + 1);
        }
        
        return totalSubarrays;
    }

public:
    int exactlyK(vector<int> &arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};
