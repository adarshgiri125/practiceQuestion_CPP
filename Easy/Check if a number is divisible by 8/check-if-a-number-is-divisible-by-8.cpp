//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        if(n > 3){
            int val = n - 3;
            string a = s.substr(val,3);
      
            int b = stoi(a);
            if(b % 8 == 0) return 1;
            else return -1;  
        }
        else{
            int b = stoi(s);
            if(b % 8 == 0) return 1;
            else return -1;
        }
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends