class Solution {
public:
    string result;

    void isLowercase(char c) {
        result += c;
    }

    void isAstrik() {
        if(!result.empty()){
            result.pop_back();
        }
    }

    void isDuplicate(){
        result+=result;
    }

    void rev(string &res) {
        int low = 0, high = res.length() - 1;

        while (low < high) {
            char temp = res[low];
            res[low] = res[high];
            res[high] = temp;
            high--;
            low++;
        }
    }

    string processStr(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                isLowercase(s[i]);
            } else if (s[i] == '*') {
                isAstrik();
            } else if(s[i]=='#'){
                isDuplicate();
            }else {
                rev(result);
            }
        }

        return result;
    }
};