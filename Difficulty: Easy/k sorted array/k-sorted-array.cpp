// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<int>sortedarr(arr,arr+n);
        sort(sortedarr.begin(),sortedarr.end());
        
        unordered_map<int,int>position;
        for(int i=0;i<n;i++){
            position[sortedarr[i]]=i;
        }
        for(int i=0;i<n;i++){
            int index=position[arr[i]];
            if(abs(index-i)>k){
                return "No";
            }
        }
        return "Yes";
    }
};