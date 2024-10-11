class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for (int i=0; i<times.size(); i++) {
            times[i].push_back(i);
        }
        sort(times.begin(), times.end());
        
        vector<int> seats;
        for (vector<int> afriend: times) {
            int i = 0;
            if (seats.size() == 0) {
                seats.push_back(afriend[1]);
            } else {
                while (i < seats.size() && afriend[0] < seats[i]) {
                    i++;
                }
                if (i < seats.size()) {
                    seats[i] = afriend[1];
                } else {
                    seats.push_back(afriend[1]);
                }
            }
            if (afriend[2] == targetFriend) return i;
        }
        return 0;
    }
};