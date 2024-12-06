//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
   int hIndex(vector<int>& a) {
        auto ok = [&](int m){
            int cnt=0;
            for(auto it:a){
                if(it>=m) cnt++;
            }
            
            return cnt>=m;
        };
        
        int l=0,h=1e9;
        int ans = 0;
        while(l<=h){
            int m = l + (h-l)/2;
            if(ok(m)){
                ans = m;
                l=m+1;
            }
            else h=m-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends