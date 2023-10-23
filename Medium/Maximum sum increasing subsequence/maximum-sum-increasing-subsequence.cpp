//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n) {
        if (n == 0) {
            return 0; 
        }
    
        vector<int> maxSum(n);
        vector<int> result;
    
        for (int i = 0; i < n; i++) {
            maxSum[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && maxSum[i] < maxSum[j] + arr[i]) {
                    maxSum[i] = maxSum[j] + arr[i];
                }
            }
        }
    
        int maxSumValue = *max_element(maxSum.begin(), maxSum.end());
    
        
        int currentMax = maxSumValue;
        for (int i = n - 1; i >= 0; i--) {
            if (maxSum[i] == currentMax) {
                result.push_back(arr[i]);
                currentMax -= arr[i];
            }
        }
    
        return maxSumValue;
    }
 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends