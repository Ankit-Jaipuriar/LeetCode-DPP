class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char min_char_to_change='{';
        bool needs_change=false;

        for(char c:s){
            if(c!='a'){
                needs_change=true;
                if(c<min_char_to_change){
                    min_char_to_change=c;
                }
            }
        }

        if(!needs_change){
            return 0;
        }

        int pos = min_char_to_change-'a';
        return 26-pos;

    }
};