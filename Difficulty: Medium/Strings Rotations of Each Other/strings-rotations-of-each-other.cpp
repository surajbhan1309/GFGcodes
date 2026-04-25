class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string s=s1+s1;
        if(s.find(s2)!=string::npos){
            return true;
        }
        return false;
    }
};