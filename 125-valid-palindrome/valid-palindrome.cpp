class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(!isalpha(s[i]) && !isdigit(s[i])){
                continue;
            }else{
                if(isalpha(s[i])){
                char a = tolower(s[i]);
                res.push_back(a);
                }else{
                    res.push_back(s[i]);
                }
            }
        }
       string rev = "";
       for(int j=res.size()-1;j>=0;j--){
        rev.push_back(res[j]);
       }
        return rev==res;
    }
};