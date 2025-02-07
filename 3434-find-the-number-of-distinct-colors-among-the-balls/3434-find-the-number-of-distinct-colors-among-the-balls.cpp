class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;         // Stores {ball -> color}
        unordered_map<int, int> freq;       // Stores {color -> count}
        vector<int> ans;

        for (auto& q : queries) {
            int x = q[0];
            int color = q[1];

            // Remove old color if it exists
            if (mp.find(x) != mp.end()) {
                int oldColor = mp[x];
                freq[oldColor]--;  // Decrease frequency
                if (freq[oldColor] == 0) freq.erase(oldColor); // Remove if no more occurrences
            }

            // Assign new color
            mp[x] = color;
            freq[color]++;  // Increase new color count

            // Store the number of distinct colors
            ans.push_back(freq.size());
        }
        return ans;
    }
};

