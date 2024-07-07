class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int a = numBottles, b = numExchange;
        int sum = numBottles;

        while (a >= b) {
            int d = a / b;
            int rem = a % b;
            sum += d;
            a = d + rem;
        }

        return sum;
    }
};