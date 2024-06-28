//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        int i=0;
        int n=arr.size();
        string ans="";
        
         for(int j=0;j<n;j++){
          int p=0,q=n-1;
          while(p<=q){
              if(arr[i][p]!=arr[i][q]){
                  break;
              }
              p++;
              q--;
          }
           if(p>=q){
              return to_string(i)+" R";
          }
         i++;
    }
    
    
    i=0;
    
    
    
       for(int j=0;j<n;j++){
          int p=0,q=n-1;
          while(p<=q){
              if(arr[p][j]!=arr[q][j]){
                  break;
              }
              p++;
              q--;
          }
          if(p>=q){
              return to_string(i)+" C";
          }
         
         i++;
    }
    
    
    
    
    
    return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends