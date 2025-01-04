//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size(), c = 0;
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                long long s = (long long)arr[i] + arr[l] + arr[r];
                if(s == target){
                    if(arr[l] == arr[r]){
                        long long t = r - l + 1;
                        c += (t * (t - 1)) / 2;
                        break;
                    }
                    int lc = 1, rc = 1;
                    while(l + 1 < r && arr[l] == arr[l + 1]){
                        l++;
                        lc++;
                    }
                    while(r - 1 > l && arr[r] == arr[r - 1]){
                        r--;
                        rc++;
                    }
                    c += lc * rc;
                    l++;
                    r--;
                } else if(s < target) l++;
                else r--;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends