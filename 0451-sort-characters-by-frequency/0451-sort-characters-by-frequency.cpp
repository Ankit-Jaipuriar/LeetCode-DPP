class Solution {
public:
    struct node {
        char val;
        int freq;
    };
    
    struct cmp {
        bool operator()(node a, node b) {
            if (a.freq == b.freq) {
                return a.val > b.val; 
            }
            return a.freq > b.freq; 
        }
    };
    
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        
        vector<node> arr;
        for (auto &it : mp) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(), cmp());
        
        string result = "";
        for (auto &it : arr) {
            result += string(it.freq, it.val);
        }
        
        return result;
    }
};
