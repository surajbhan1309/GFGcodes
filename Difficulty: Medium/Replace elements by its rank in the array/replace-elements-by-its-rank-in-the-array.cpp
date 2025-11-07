// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int>dummy=arr;
        int n=N;
        sort(dummy.begin(),dummy.end());
        dummy.erase(unique(dummy.begin(), dummy.end()), dummy.end());
        unordered_map<int,int>rank;
        for(int i=0;i<dummy.size();i++){
            rank[dummy[i]]=i+1;
        }
        for(int i=0;i<n;i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};
