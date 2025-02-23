class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string second = strs.back();

        int minLen = min(first.size(),second.size());

        int i=0;
        while(i<minLen && first[i]==second[i]){
            i++;
        }
        return first.substr(0,i);
    }
};