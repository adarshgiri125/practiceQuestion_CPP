//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i,int j,int s,string &word,vector<vector<char>>& mat){
        if (s == word.size()) return true;
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[s]) return false;

        char temp = mat[i][j]; 
        mat[i][j] = '#';  // mark visited

        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // Right, Down, Left, Up
        for (auto& d : dir) {
            if (dfs(i + d[0], j + d[1], s + 1, word, mat)) return true;
        }

        mat[i][j] = temp; //backtrack
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, word, mat)) return true; //check every cell
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends