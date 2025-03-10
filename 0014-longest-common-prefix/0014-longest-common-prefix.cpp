class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(), strs.end()); // it will sort lexicographically
        // eg: flight, flow, flower

        string s1 = strs[0];
        string s2 = strs[n-1];
        int index = 0;
        while (index < s1.size()) {
            if (s1[index] == s2[index]) {
                index++;
            } else {
                break;
            }
        }

        return s1.substr(0, index); 
    }
};
