class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        for(int i = 0; i < s.size(); i++) {
            bool match = true;
            for(int j = 0; j < s.size(); j++) {
                if(s[(i + j) % s.size()] != goal[j]) {
                    match = false;
                    break;
                }
            }
            if(match) return true;
        }
        
        return false;
    }
};


