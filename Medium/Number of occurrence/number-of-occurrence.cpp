//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int count(int arr[], int n, int x) {
        int s = 0;
        int e = n - 1;
        int pos = -1; 
        
            while (s <= e) { 
                int mid = s + (e - s) / 2; 
                
                if (x < arr[mid]) {
                    e = mid - 1;
                } else if (x > arr[mid]) {
                    s = mid + 1;
                } else {
                    pos = mid; 
                    e = mid - 1;
                }
            }
    
            if (pos == -1) {
                return 0; 
            }
    
            int count = 0;
            for (int i = pos; i < n && arr[i] == x; i++) { 
                count++;
            }
        
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends