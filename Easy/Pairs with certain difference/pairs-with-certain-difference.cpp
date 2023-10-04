//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here 
        // vector<int> ans;
        sort(arr,arr+n);
        int sum = 0;
        for(int i = n-1; i>0; i--){
            int value = arr[i] - arr[i - 1];
            if(value < k){
               
                sum += arr[i];
                sum += arr[i-1];
                i--;
                
            }
           
            
        }
        return sum;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends