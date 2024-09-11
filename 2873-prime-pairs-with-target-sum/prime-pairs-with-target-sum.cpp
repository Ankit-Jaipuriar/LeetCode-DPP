class Solution {
public:
    vector<bool> solve(int n){
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> v;
        vector<bool> prime = solve(n);
        for(int i = 2; i <= n / 2; i++){ 
            if(prime[i] && prime[n - i]){
                v.push_back({i, n - i});
            }
        }
        return v;
    }
};
