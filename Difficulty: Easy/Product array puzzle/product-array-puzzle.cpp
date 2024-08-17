//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
          vector<long long int > suffix;
          vector<long long int > prefix;
          long long int mul = 1;
          for(int i = 0; i<nums.size(); i++){
              mul *= nums[i];
              suffix.push_back(mul);
          }
          mul = 1;
          for(int i = nums.size() - 1; i >= 0; i--){
              mul *= nums[i];
              prefix.push_back(mul);
          }
          
          reverse(prefix.begin(), prefix.end());
          
          vector<long long int> ans;
          for(int i = 0; i < nums.size(); i++){
              long long left = 1;
              long long right = 1;
              if(i > 0) left = suffix[i - 1];
              if(i < nums.size() - 1) right = prefix[i + 1];
              
              long long int temp = left * right;
              ans.push_back(temp);
          }
         return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends