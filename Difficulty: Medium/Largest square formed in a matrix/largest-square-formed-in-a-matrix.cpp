//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> next(vector<int> &mat){
        int n = mat.size();
        
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && mat[st.top()] > mat[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pre(vector<int> &mat){
        int n = mat.size();
        
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mat[st.top()] > mat[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {

        for(int i=1; i< n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1)
                    mat[i][j] += mat[i-1][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> right = next(mat[i]);
            vector<int> left = pre(mat[i]);
            for(int j = 0; j<m;j++){
                ans = max(ans, min(right[j]-left[j]-1,mat[i][j]));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends