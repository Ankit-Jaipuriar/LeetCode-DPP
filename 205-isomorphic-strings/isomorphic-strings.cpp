class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int str1 = s.size();
        int str2 = t.size();
        if(str1!=str2){
            return false;
        }
        unordered_map<char, vector<int>> mp1;
        unordered_map<char, vector<int>> mp2;
        
        for(int i=0;i<str1;i++){
            mp1[s[i]].push_back(i);
        }
        for(int j=0;j<str2;j++){
            mp2[t[j]].push_back(j);
        }
        for(int k=0;k<str1;k++){
            if(mp1[s[k]]!=mp2[t[k]]){
                return false;
            }
        }
        return true;
    }
};