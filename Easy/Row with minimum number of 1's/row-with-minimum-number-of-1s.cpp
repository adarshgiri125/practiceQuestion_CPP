//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int ans = INT_MAX;
  int result = INT_MAX;
    int minRow(int n, int m, vector<vector<int>> arr) {
        for(int i = n-1; i>= 0; i--){
            int cnt = 0;
            for(int j = m-1; j>=0; j--){
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
            if(ans >= cnt){
                ans = cnt;
                result = i+1;
            }
            
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends