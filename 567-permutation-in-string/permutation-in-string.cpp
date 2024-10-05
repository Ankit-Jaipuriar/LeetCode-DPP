class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto i : s1) {
            mp[i]++;
        }

        int count = mp.size();
        int k = s1.size();
        for (int i = 0; i < s2.size(); i++) {
            if (mp.find(s2[i]) != mp.end()) {
                mp[s2[i]]--;
                if (mp[s2[i]] == 0) {
                    count--;
                }
            }
            if (i >= k) {
                if (mp.find(s2[i - k]) != mp.end()) {
                    mp[s2[i - k]]++;
                    if (mp[s2[i - k]] == 1) {
                        count++;
                    }
                }
            }
            if (count == 0) {
                return true;
            }
        }

        return false;
    }
};
