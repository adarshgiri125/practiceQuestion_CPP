//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int _0s = 0;
        int _2s = n-1;
        int i = 0;
        
        while( i <= _2s)
        {
            if(arr[i] == 0)
            {
                arr[i] = arr[_0s];
                arr[_0s] = 0;
                _0s++;
                i++;
            }
            else if(arr[i] == 2)
            {
                arr[i] = arr[_2s];
                arr[_2s] = 2;
                _2s--;
            }
            else
            {
                i++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends