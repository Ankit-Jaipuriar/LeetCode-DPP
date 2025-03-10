class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int x = num[i]-'0';
            if(x%2!=0){
                return num.substr(0,i+1); //here i+1 means excluding
            }
        }
        return "";
    }
};