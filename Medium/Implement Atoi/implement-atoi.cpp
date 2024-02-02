//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int n = s.size();
        int ans = 0;
        bool neg = false;
        int i = 0;
        if(s[i] == '-'){
            i = 1;
            neg = true;
        }
        
        for( i; i<n; i++){
            int value = s[i] - '0';
          
            if(value >= 0 && value <=9){
                ans = ans + value * (pow(10,n-i-1)); 
                // cout << ans << endl;
                
            }
            else return -1;
        }
        if(neg){
         
            return (-1 * ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends