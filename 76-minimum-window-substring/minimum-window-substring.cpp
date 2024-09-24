class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp; 
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        int minLen = 1e9;
        int sidx = -1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        while (r < n) {
            if (mp[s[r]] > 0) {
                cnt++;
            }
            mp[s[r]]--; 
            r++; 
            while (cnt == m) {
                if (r - l < minLen) {
                    minLen = r - l;
                    sidx = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++; 
            }
        }

        return sidx == -1 ? "" : s.substr(sidx, minLen);
    }
};