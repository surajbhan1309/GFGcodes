// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        long long maxsum=-1;
        long long currsum=0;
        int maxstart=-1;
        int currstart=0;
        bool non_negative=false;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                non_negative=true;
                currsum+=arr[i];
            }
            else{
                if(currsum>maxsum){
                    maxsum=currsum;
                    maxstart=currstart;
                }
                currsum=0;
                currstart=i+1;
            }
        }
        //check for last subarray
        if(currsum>maxsum){
            maxsum=currsum;
            maxstart=currstart;
        }
        if(!non_negative) return {-1};
        
        vector<int> ans;
        for (int i = maxstart; i < arr.size() && arr[i] >= 0; i++)
            ans.push_back(arr[i]);

        return ans;
        
    }
};