//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int n, int prices[]) {
    vector<vector<int > > curr(2,vector< int > (K+1,0));
    vector<vector<int > > prev(2,vector< int > (K+1,0));
   
   
    for(int ind = n-1; ind>= 0; ind--){
       for(int buy = 0; buy <= 1; buy++){
           for(int cap = 1; cap <= K; cap++){
                
                if(buy == 1){
                    curr[buy][cap] = max(-prices[ind] + prev[0][cap], 
                                       0 + prev[1][cap]); 
                }
                else{
                   curr[buy][cap] = max(prices[ind] + prev[1][cap-1],
                                        0 + prev[0][cap]);
                }
             
           }
       }
       prev = curr;
   }
   return prev[1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends