class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long l1 = 0, l2 = 0;
        k--;
        int n = weights.size();
        vector<long long> ans;

        for (int i = 1; i < n; i++) {
            ans.push_back(weights[i] + weights[i - 1]);
        }

        sort(ans.begin(), ans.end(), greater<long long>());

        int n1 = ans.size();

        for (int i = 0; i < k; i++) {
            l2 += ans[i];
            l1 += ans[n1 - 1 - i];
        }

        return (l2 - l1);
    }
};
