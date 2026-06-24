class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        
        // Ensure binary search is performed on the smaller array for O(log(min(n, m)))
        if (n > m) {
            return kthElement(b, a, k);
        }
        
        // Bounds for the number of elements we can pick from array 'a'
        int low = max(0, k - m);
        int high = min(k, n);
        
        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;
            
            // Fetch boundary elements, using INT_MIN/INT_MAX for edge boundaries
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];
            
            // Check if partition is valid
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            // Too many elements from array 'a'
            else if (l1 > r2) {
                high = cut1 - 1;
            } 
            // Too few elements from array 'a'
            else {
                low = cut1 + 1;
            }
        }
        return -1;
    }
};
