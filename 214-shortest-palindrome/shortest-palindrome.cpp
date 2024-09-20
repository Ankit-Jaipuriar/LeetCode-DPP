class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        vector<int> lps(temp.size(), 0);
        for (int i = 1; i < temp.size(); i++) {
            int j = lps[i - 1];     
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }   
            if (temp[i] == temp[j]) {
                j++;
            }    
            lps[i] = j;
        }
        int longest_palindrome_prefix_length = lps.back();
        string non_palindrome_suffix = s.substr(longest_palindrome_prefix_length);
        reverse(non_palindrome_suffix.begin(), non_palindrome_suffix.end());
        
        return non_palindrome_suffix + s;
    }
};
