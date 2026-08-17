class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len - 1 < n; left++) {
                int right = left + len - 1;

                for (int k = left; k < right; k++) {
                    int leftSum = prefix[k + 1] - prefix[left];
                    int rightSum = prefix[right + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        dp[left][right] = max(
                            dp[left][right],
                            leftSum + dp[left][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        dp[left][right] = max(
                            dp[left][right],
                            rightSum + dp[k + 1][right]
                        );
                    }
                    else {
                        dp[left][right] = max(
                            dp[left][right],
                            leftSum + max(dp[left][k], dp[k + 1][right])
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
