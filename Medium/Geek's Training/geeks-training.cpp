//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& points, int n, int ind,int dp[][4]){
        if(n == 0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i != ind) maxi = max(maxi,points[n][i]);
            }
            return maxi;
        }
        if(dp[n][ind] != -1) return dp[n][ind]; 
        int maxi = 0;
        for(int i = 0; i<3; i++){
            int value = 0;
            if(i != ind)
            value = points[n][i] + solve(points,n-1,i,dp);
            
            maxi = max(maxi,value);
        }
        return dp[n][ind] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        int dp[n][4];
        memset(dp,-1,sizeof(dp));
        return solve(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends