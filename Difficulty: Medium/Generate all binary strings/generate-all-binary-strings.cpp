class Solution {
  public:
    void allbin(string str,int n,vector<string>&ans){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        allbin(str+'0',n,ans);
        allbin(str+'1',n,ans);

    }
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        allbin("",n,ans);
        return ans;
    }
};