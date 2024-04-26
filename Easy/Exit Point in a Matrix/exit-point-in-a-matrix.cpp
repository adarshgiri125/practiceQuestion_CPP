//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& matrix, int d, int r, int c, int n, int m) {
    if (matrix[r][c] == 1) {
        if (d == 0) {
            if (r + 1 >= n) {
                return {r, c};
            }
            matrix[r][c] = 0;
            return dfs(matrix, 1, r + 1, c, n, m);
        }
        if (d == 1) {
            if (c - 1 < 0) {
                return {r, c};
            }
            matrix[r][c] = 0;
            return dfs(matrix, 2, r, c - 1, n, m);
        }
        if (d == 2) {
            if (r - 1 < 0) {
                return {r, c};
            }
            matrix[r][c] = 0;
            return dfs(matrix, 3, r - 1, c, n, m);
        }
        if (d == 3) {
            if (c + 1 >= m) {
                return {r, c};
            }
            matrix[r][c] = 0;
            return dfs(matrix, 0, r, c + 1, n, m);
        }
    } else if (matrix[r][c] == 0) {
        if (d == 0) {
            if (c + 1 >= m) {
                return {r, c};
            }
            return dfs(matrix, 0, r, c + 1, n, m);
        }
        if (d == 1) {
            if (r + 1 >= n) {
                return {r, c};
            }
            return dfs(matrix, 1, r + 1, c, n, m);
        }
        if (d == 2) {
            if (c - 1 < 0) {
                return {r, c};
            }
            return dfs(matrix, 2, r, c - 1, n, m);
        }
        if (d == 3) {
            if (r - 1 < 0) {
                return {r, c};
            }
            return dfs(matrix, 3, r - 1, c, n, m);
        }
    }
    
    return {0, 0}; 
}

vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
    return dfs(matrix, 0, 0, 0, n, m);
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends