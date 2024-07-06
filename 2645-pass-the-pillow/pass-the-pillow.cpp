class Solution {
public:
    int passThePillow(int n, int time) {
        int i= 1; 
        bool flag = true;

        while(time--){
            if(i>=n) flag = !flag;
            if(flag){
                i++;
            }else{
                i--;

            }
            if(i<=1) flag = !flag;
        }
        return i;
    }
};