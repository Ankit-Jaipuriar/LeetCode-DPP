class Solution {
public:
    vector<string> solve(string s) {
        vector<string> v;
        string temp;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(!temp.empty()) {
                    v.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }
        if(!temp.empty()) {
            v.push_back(temp);
        }
        return v;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = solve(sentence1);
        vector<string> s2 = solve(sentence2);
        int n = s1.size();
        int m = s2.size();
        int i = 0, j = 0;

        while(i < n && j < m && s1[i] == s2[j]) {
            i++;
            j++;
        }
        while(i < n && j < m && s1[n-1] == s2[m-1]) {
            n--;
            m--;
        }

        return i == n || j == m;
    }
};
