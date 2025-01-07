//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count_num(vector<int>::iterator start, vector<int>::iterator end, int target){
        auto lower = lower_bound(start, end, target);
        auto upper = upper_bound(start, end, target);
        return upper - lower;
    }
    int countPairs(vector<int> &arr, int target) {
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            int req = target-arr[i];
            ans+= count_num(arr.begin()+i+1,arr.end(),req);
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends