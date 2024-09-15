class Solution {
public:
    int findTheLongestSubstring(string s) {
    unordered_map<int, int> pos;
    pos[0] = -1;
    int state = 0, maxLength = 0;
    vector<int> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') state ^= 1 << 0;
        else if (s[i] == 'e') state ^= 1 << 1;
        else if (s[i] == 'i') state ^= 1 << 2;
        else if (s[i] == 'o') state ^= 1 << 3;
        else if (s[i] == 'u') state ^= 1 << 4;
        if (pos.find(state) != pos.end()) {
            maxLength = max(maxLength, i - pos[state]);
        } else {
            pos[state] = i;
        }
    }
    
    return maxLength;
    }
};