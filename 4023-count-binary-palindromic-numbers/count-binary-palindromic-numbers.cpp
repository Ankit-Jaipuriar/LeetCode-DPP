class Solution {
public:
int countBinaryPalindromes(long long n) {
    if (n == 0) return 1;

    string s_n = "";
    long long temp_n = n;
    while(temp_n > 0){
        s_n = (temp_n % 2 == 0 ? "0" : "1") + s_n;
        temp_n /= 2;
    }
    int len_n = s_n.length();

    // Part 1: Count all palindromes SHORTER than n
    int count = 1; // Start with 0
    for (int L = 1; L < len_n; ++L) {
        long long half_len = (L + 1) / 2;
        count += pow(2, half_len - 1);
    }

    // Part 2: Count palindromes with the SAME length as n
    int half_len_n = (len_n + 1) / 2;
    string prefix_n_str = s_n.substr(0, half_len_n);
    long long prefix_n_val = stoll(prefix_n_str, nullptr, 2);

    long long start_base = pow(2, half_len_n - 1);
    count += prefix_n_val - start_base;

    // Finally, check the palindrome made from n's own prefix
    string first_half = prefix_n_str;
    string second_half = s_n.substr(0, len_n / 2);
    reverse(second_half.begin(), second_half.end());
    string p_from_prefix_str = first_half + second_half;
    long long p_from_prefix_val = stoll(p_from_prefix_str, nullptr, 2);

    if (p_from_prefix_val <= n) {
        count++;
    }

    return count;
    }
};