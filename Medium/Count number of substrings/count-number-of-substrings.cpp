//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	return atmost(s,k) - atmost(s,k-1);
    }
    
    long long atmost(string s, int k){
        int n = s.length();
        vector<int> arr(26,0);
        int left = 0;
        long long ans = 0;
        int dis = 0;
        
        for(int i = 0; i<n; i++){
            arr[s[i] - 'a']++;
            if((arr[s[i] - 'a']) == 1) dis++;
            
            while(dis > k){
                arr[s[left] - 'a']--;
                if((arr[s[left] - 'a']) == 0) dis--;
                left++;
            }
            
            ans = ans + (i - left + 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends