class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans=0, mx=1;
        int sz = nums.size();
        vector<int> lis(sz, 1), dp(sz, 1);
        
        for(int i=1; i<sz; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(lis[i] < lis[j]+1){
                        lis[i] = 1+lis[j];
                        dp[i] = dp[j];
                    }
                    else if(lis[i] == 1 + lis[j]){
                        dp[i] += dp[j];
                    }
                }
            }
            mx = max(mx, lis[i]);
        }
        for(int i=0; i<sz; i++){
            if(lis[i] == mx){
                ans += dp[i];
            }
        }
        return ans;
    }
};
