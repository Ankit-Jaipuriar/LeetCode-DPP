class Solution {
public:
    string reverseWords(string s) {
        // 1. reverse the string
        // 2. take each word and reverse it
        // 3. add space before reverse word before adding to final string
        string ans = "";
        reverse(s.begin(), s.end());
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {  //this loop will only run if word has any characters not space
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.size()>0) {   //add word only if it has some characters not space
                ans += ' ' + word;
            }
        }
        return ans.substr(1);
    }
};
