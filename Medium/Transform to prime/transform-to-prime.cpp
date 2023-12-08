//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isPrime(int i){
        for(int j = 2; j<i; j++){
            if(i % j == 0){
                return 0;
            }
            
        }
        return 1;
    }
    int minNumber(int arr[],int N)
    {
        int ans;
        int sum = 0;
        for(int i = 0; i<N; i++){
            sum += arr[i];
        }
        if(sum == 1) return 1;
        for(int i = sum; i<1e7; i++){
            if(isPrime(i)){
                ans = i;
                break;
            }
        }

        ans = ans - sum;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends