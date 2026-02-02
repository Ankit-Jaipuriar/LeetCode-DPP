class Solution {
    public Integer bs(int low,int high, int i, int[][] matrix, int target){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[i][mid]==target) return 1;
            else if(target>matrix[i][mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        for(int i=0;i<n;i++){
            if(target<matrix[i][0] || target>matrix[i][m-1]) continue;

            int idx = bs(0,m-1,i,matrix,target);
            if(idx!=-1) return true;
        }
        return false;
    }
}
