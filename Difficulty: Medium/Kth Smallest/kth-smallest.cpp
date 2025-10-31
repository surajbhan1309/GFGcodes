class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>>maxheap;
        for(auto &num:arr){
            maxheap.push(num);
            if(maxheap.size()>k) maxheap.pop();
        }
        return maxheap.top();
    }
};