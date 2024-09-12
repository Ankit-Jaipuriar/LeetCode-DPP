class Solution {
private:
    bool isPrime(const int& n)
    {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (!(n % i)) {
                return false;
            }
        }
        return true;
    }

    bool isPal(int n)
    {
        if (n < 0) {
            return false;
        }
        int original = n;
        int reversed = 0;
        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }
        return original == reversed;
    }

public:
    int primePalindrome(int n) 
    {
        while(!(isPal(n) && isPrime(n))) {
            n++;
        }
        return n;
    }

};