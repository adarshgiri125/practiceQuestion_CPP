//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    long long sequence(int n){
        // code here
        int val = 1;
        return solve(n+1 , 1 , val);
    }
    
    long long solve(int n , int i , int &val){
        if(i == n) return 0;
        long long temp = 1;
        for(int j = 0 ; j < i ; j++){
            temp = (temp%mod * val%mod)%mod;
            val++;
        }
        
        return (temp%mod + solve(n , i+1 , val)%mod)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends