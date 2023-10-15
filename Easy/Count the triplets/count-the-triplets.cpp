//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    sort(arr,arr+n);
  
        int count=0;
        for(int i=n-1;i>=2;i--){
          int s=0;
          int e=i-1;
          while(s<e){
              if(arr[s]+arr[e]==arr[i]){
                  count++;
                  s++;
                  e--;
              }
              else if(arr[s]+arr[e]<arr[i]){
                  s++;
              }
              else{
                  e--;
              }
          }
      }
         
        return count;
   }
	
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends