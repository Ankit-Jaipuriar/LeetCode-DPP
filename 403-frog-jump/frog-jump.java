class Solution {
    public boolean canCross(int[] stones) {
    // frog - starts on the first stone (position 0)
    //
    // goal - reach the last stone without falling into water
    //
    // setup -
    // stones[] represents positions of stones in the river (sorted, increasing)
    //
    // rules -
    // 1. frog can jump only on stones (cannot land in water)
    // 2. first jump must be exactly 1 unit
    // 3. if the last jump was k units,
    //    next jump can be k-1, k, or k+1 units
    // 4. jump distance must be > 0
    // 5. frog can jump only in the forward direction
    //
    // result -
    // return true if frog can reach the last stone
    // return false otherwise
 
        int n=stones.length;
        boolean[][] dp = new boolean[n][n+1];

       dp[0][0]=true;
       if(n>1 && stones[1]==1){
        dp[1][1]=true;
       }else{
        return false;
       }

       for(int i=1;i<n;i++){
        for(int k=1;k<=n;k++){
            if(!dp[i][k]) continue;

            for(int steps=k-1;steps<=k+1;steps++){
                int nextpos = stones[i]+steps;

                for(int j=i+1;j<n;j++){
                    if(stones[j]==nextpos){
                        dp[j][steps]=true;
                        break;
                    }
                    if(stones[j]>nextpos) break;
                }
            }
        }
       }
       for(int k=0;k<=n;k++){
        if(dp[n-1][k]){
            return true;
        }
       }
       return false;
}
};