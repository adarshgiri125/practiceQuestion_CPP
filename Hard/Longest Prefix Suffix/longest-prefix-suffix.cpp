//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	  int n = s.size();
	  vector<int> KP(n, 0);
	  
	  int len = 0;
	  int i = 1;
	  int ans = 0;
	  while(i < n){
	      if(s[i] == s[len]){
	          len++;
	          KP[i] = len;
	          ans = max(ans, len);
	          i++;
	      }
	      else if(s[i] != s[len]){
	          if(len == 0){
	             i++;
	          }else{
	             len = KP[len - 1];
	          }
	      }
	  }
	  return KP.back();
	  
	  
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
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends