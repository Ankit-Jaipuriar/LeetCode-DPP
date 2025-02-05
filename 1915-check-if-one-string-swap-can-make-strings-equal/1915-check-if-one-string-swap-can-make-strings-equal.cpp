class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        if (s1.size() != s2.size()) return false;

        vector<int> diff;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        if (diff.size() == 2) {
            int i = diff[0], j = diff[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }

        return false;
    }
};
