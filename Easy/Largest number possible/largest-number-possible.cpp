//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        int value = 0;
        int check2 = N;
        int check = S;
        string ans = "";
        while( S > 0 && N > 0){
            if(S > 9){
                ans += "9";
                value += 9;
                S -= 9;
                N--;
            }
            else{
                
                char n ='0' + S;
                value += S;
                // cout << n << endl;
                ans += n;
                S -= S;
                N--;
            }
        }
        // cout << value << " " << S << endl;
        while(N > 0){
            ans += "0";
            N--;
        }
       
        if(value != check || (check == 0 && check2 > 1)){
            return "-1"; 
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends