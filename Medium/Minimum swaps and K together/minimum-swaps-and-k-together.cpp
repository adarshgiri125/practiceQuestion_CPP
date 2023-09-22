//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) {
                count++;
            }
        }
        
        int i = 0, j = 0;  // Window [i, j]
        int swaps = INT_MAX;  // Initialize with maximum possible swaps
        int currentSwaps = 0;  // Number of swaps needed to fix the current window
        while (j < n) {
            if (j - i + 1 > count) {
                while(j-i+1>count){
                    if (arr[i] > k) {
                        currentSwaps--;
                    }
                    i++;
                }
            }
            
            if (arr[j] > k) {
                currentSwaps++;
            }
            
            if (j - i + 1 == count) {
                swaps = min(swaps, currentSwaps);
            }
            
            j++;
        }
        
        return swaps;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends