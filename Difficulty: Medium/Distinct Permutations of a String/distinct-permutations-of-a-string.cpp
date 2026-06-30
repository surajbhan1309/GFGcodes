class Solution {
private:
    void solve(int index, string s, vector<string> &ans) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }
        
        unordered_set<char> seen;
        for (int i = index; i < s.size(); ++i) {
            if (seen.count(s[i])) continue;
            seen.insert(s[i]);
            
            swap(s[index], s[i]);
            solve(index + 1, s, ans);
            swap(s[index], s[i]);
        }
    }

public:
    vector<string> findPermutation(string &s) {
        vector<string> ans;
        solve(0, s, ans);
        return ans;
    }
};
