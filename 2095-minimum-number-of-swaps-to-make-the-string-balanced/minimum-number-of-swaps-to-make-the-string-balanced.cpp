class Solution {
public:
    int minSwaps(string s) {
        int open=0,unbalanced=0;
        for(auto c:s){
            if(c=='[') open+=1;
            else if(open>0) open-=1;
            else unbalanced+=1;
        }
        return (unbalanced+1)/2;
    }
};