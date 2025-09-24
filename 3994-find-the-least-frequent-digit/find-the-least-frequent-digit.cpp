class Solution {
public:
    int getLeastFrequentDigit(int n) {

        if(n==0) return 0;
        
        map<int,int> mp;
        while(n>0){
            int lastdigit = n%10;
            mp[lastdigit]++;
            n=n/10;
        }

        int miniF=INT_MAX;
        int result=9;
        for(auto p:mp){
            if(p.second<miniF || (p.second==miniF && p.first<result)){
                miniF=p.second;
                result=p.first;
            }
        }
        return result;

    }
};