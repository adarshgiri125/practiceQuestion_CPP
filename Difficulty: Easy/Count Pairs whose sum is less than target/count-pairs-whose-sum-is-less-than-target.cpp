//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            // y <= target - arr[i]
            int y = target - arr[i];
            int idx = -1;
            int lo = i , hi = arr.size()-1;
            while(lo <= hi){
                int mid = lo + (hi-lo)/2;
                if(arr[mid] < y){
                    idx = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            if(idx >= 0)ans += idx-i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends