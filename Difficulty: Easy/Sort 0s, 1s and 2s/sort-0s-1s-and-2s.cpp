//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
    int n = arr.size();
    int i = 0;  
    int j = n - 1;  
    
    for (int x = 0; x <= j; ) {  // Iterate until x is less than or equal to j
        if (arr[x] == 0) {
            swap(arr[i], arr[x]);
            i++;
            x++;
        } else if (arr[x] == 2) {
            swap(arr[x], arr[j]);
            j--;
        } else {
            x++;
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
    }
    return 0;
}

// } Driver Code Ends