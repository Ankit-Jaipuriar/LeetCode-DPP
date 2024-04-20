class Solution {
public:
    long long int mySqrt(int x) {
       if(x==0 || x==1){
        return x;
       }
       int s = 0;
       int e = x-1;
       long long int mid = s + (e-s)/2;
       int ans = -1;
       while(s<=e){
        long long int sqr = mid*mid;
        if(sqr==x){
            return mid;
        }else if(sqr<x){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
       }
       return ans; 
    }
};