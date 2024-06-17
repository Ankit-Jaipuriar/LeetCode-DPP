class Solution {
public:
    bool judgeSquareSum(int c) {
        long s = 0;
        long e =  static_cast<long>(sqrt(c));
        while(s<=e){
            long sum = s*s + e*e;
            if(sum==c){
                return true;
            }
            if(sum<c){
                s++;
            }else{
                e--;
            }
        }
        return false;
    }
};