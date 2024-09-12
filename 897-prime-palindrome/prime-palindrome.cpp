class Solution {
public:
bool isPalindrome(int n){
    int temp = n;
    int rem=0;
    while(n>0){
        int ld = n%10;
        rem = rem*10 +ld;
        n=n/10;
    }
    return temp==rem;
}
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
    int primePalindrome(int n) {
        while(!(isPalindrome(n) && isPrime(n))){
            n++;
        }
        return n;
    }
};