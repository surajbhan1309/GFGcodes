class Solution {
  public:
    void setsum(int i,vector<int>&arr,vector<int>&ans,int sum){
        if(i==arr.size()){
            ans.push_back(sum);
            return;
        }
        setsum(i+1,arr,ans,sum+arr[i]);
        setsum(i+1,arr,ans,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        setsum(0,arr,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};