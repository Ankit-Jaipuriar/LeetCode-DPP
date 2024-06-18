
class Solution {
public:
    int fun2(vector<int>& difficulty, int k) {
        int n = difficulty.size();
        int l = -1;
        int r = n;
        while (r - 1 > l) {
            int m = (l + r) / 2;
            if (k >= difficulty[m]) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int sum = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < jobs.size(); ++i) {
            difficulty[i] = jobs[i].first;
            profit[i] = jobs[i].second;
        }
        vector<int> maxProfit(profit.size());
        maxProfit[0] = profit[0];
        for (int i = 1; i < profit.size(); ++i) {
            maxProfit[i] = max(maxProfit[i - 1], profit[i]);
        }

        sort(worker.begin(), worker.end());
        for (int i = 0; i < n; ++i) {
            int b = fun2(difficulty, worker[i]);
            if (b != -1) {
                sum += maxProfit[b];
            }
        }

        return sum;
    }
};
