class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int element=arr[i];
            while(!s.empty() && s.top()>=element) s.pop();
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(element);
        }
        return ans;
    }
    
};