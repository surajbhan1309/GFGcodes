class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto &x:arr){
            minheap.push(x);
        }
        int sum=0;
        while(minheap.size()>1){
            int firstele=minheap.top();
            minheap.pop();
            int secondele=minheap.top();
            minheap.pop();
            int element=firstele+secondele;
            minheap.push(element);
            sum+=firstele+secondele;
        }
        return sum;
    }
};