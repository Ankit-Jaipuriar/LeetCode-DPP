class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s;
        for (char c : word) s.insert(c);
        int ans = 0;
        for (char x = 'a'; x <= 'z'; x++) {
            if (s.count(x) && s.count(x - 'a' + 'A'))
                ans++;
        }
        return ans;
    }
};