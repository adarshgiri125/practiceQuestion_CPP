//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
     int rowWithMax1s(vector<vector<int> > &arr) {
        
        //rowNumber tells which row it is , if there is not any zero output will be returned as -1 .
        int rowNumber = -1;
        //keeps the track of one Count 
        int oneCount = 0;
        
        for(int i = 0; i<arr.size(); i++){
            int count = 0;
            for(int j = 0; j<arr[i].size(); j++){
                if(arr[i][j] == 1){
                    count++;
                }
            }
            //if there is 1s in the array count will be something
            if(count > oneCount){
                oneCount = count;
                rowNumber = i;
            }
        }
        return rowNumber;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends