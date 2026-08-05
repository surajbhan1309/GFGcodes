class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(arr,ans,path,0);
        return ans;
    }
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&path,int start){
        if(start==arr.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(arr[start]);
        solve(arr,ans,path,start+1);
        path.pop_back();
        solve(arr,ans,path,start+1);
    }
};