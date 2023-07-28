class Solution {
    int[][] dp;

    private int scoreHelper(int[] nums, int left, int right){
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        if(left == right){
            return nums[left];
        }

        int l = nums[left] - scoreHelper(nums, left+1, right);
        int r = nums[right] - scoreHelper(nums, left, right-1);

        dp[left][right] = Math.max(l, r);
        return dp[left][right];
    }

    public boolean PredictTheWinner(int[] nums) {
        int sz = nums.length;
        dp = new int[sz][sz];

        for(int i=0; i<sz; i++){
            Arrays.fill(dp[i], -1);
        }
        return scoreHelper(nums, 0, sz-1) >= 0;
    }
}
