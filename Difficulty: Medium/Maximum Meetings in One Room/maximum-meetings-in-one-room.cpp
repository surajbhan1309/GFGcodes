class Solution {
    struct Meeting {
        int start;
        int finish;
        int index;
    };

    static bool compare(const Meeting &a, const Meeting &b) {
        if (a.finish != b.finish) {
            return a.finish < b.finish;
        }
        return a.index < b.index;
    }

public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<Meeting> meetings(n);
        for (int i = 0; i < n; i++) {
            meetings[i] = {s[i], f[i], i + 1};
        }
        
        sort(meetings.begin(), meetings.end(), compare);
        
        vector<int> result;
        if (n == 0) return result;
        
        result.push_back(meetings[0].index);
        int last_finish = meetings[0].finish;
        
        for (int i = 1; i < n; i++) {
            if (meetings[i].start > last_finish) {
                result.push_back(meetings[i].index);
                last_finish = meetings[i].finish;
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
