class Solution {
  public:
    int dp[101][101][101];

    int lcs(string& A, string& B, string& C, int i, int j, int k) {
        if (i == 0 || j == 0 || k == 0) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
    
        if (A[i-1] == B[j-1] && B[j-1] == C[k-1]) {
            return dp[i][j][k] = 1 + lcs(A, B, C, i-1, j-1, k-1);
        }
        return dp[i][j][k] = max({
            lcs(A, B, C, i-1, j, k),
            lcs(A, B, C, i, j-1, k),
            lcs(A, B, C, i, j, k-1)
        });
    }
    
    int lcsOf3(string& A, string& B, string& C) {
        memset(dp, -1, sizeof(dp));
        return lcs(A, B, C, A.size(), B.size(), C.size());
    }

};
