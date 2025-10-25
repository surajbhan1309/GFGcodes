class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n=s.size();
        int left=0;
        vector<int>count(3,0);
        long long ans=0;
        int have=0;
        for(int right=0;right<n;right++){
            count[s[right]-'a']++;
            if(count[s[right]-'a']==1) have++;
            while(have==3){
               ans+=n-right;
               count[s[left]-'a']--;
               if(count[s[left]-'a']==0) have--;
               left++;
            }
        }
        return ans;
    }
};