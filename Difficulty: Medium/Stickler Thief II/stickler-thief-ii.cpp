//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int dp[100001];
    int solve(vector<int>& arr,int i,int n)
    {
        if(i > n)
        return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }    
        int pick = 0,not_pick=0;
        
        pick = arr[i]+solve(arr,i+2,n);
        not_pick = solve(arr,i+1,n);
        
        return dp[i]=max(pick,not_pick);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        int include_first=solve(arr,0,n-2);
        memset(dp,-1,sizeof(dp));
        int include_last = solve(arr,1,n-1);
        return max(include_first,include_last);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends