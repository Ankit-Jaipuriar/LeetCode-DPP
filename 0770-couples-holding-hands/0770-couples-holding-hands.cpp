class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int second = first ^ 1; 
            
            if (row[i + 1] != second) {
                swaps++;
                int partnerIndex = pos[second]; 
                
                pos[row[partnerIndex]] = i + 1;
                pos[row[i + 1]] = partnerIndex;
                swap(row[i + 1], row[partnerIndex]);
            }
        }
        return swaps;
    }
};
