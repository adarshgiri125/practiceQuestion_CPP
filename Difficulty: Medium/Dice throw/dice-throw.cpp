class Solution {
  public:
    const int MOD = 1e9 + 7;

    long long dp[51][1001];
    
    int solve(int m, int n, int x, int round, int sum) {
        if (round == n) return sum == x ? 1 : 0;
        if (dp[round][sum] != -1) return dp[round][sum];
    
        long long ways = 0;
        for (int j = 1; j <= m; j++) {
            if (sum + j <= x) {
                ways = (ways + solve(m, n, x, round + 1, sum + j)) % MOD;
            }
        }
    
        return dp[round][sum] = ways;
    }
    
    int noOfWays(int m, int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, x, 0, 0);
    }



};