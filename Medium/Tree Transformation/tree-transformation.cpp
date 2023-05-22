//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        
        vector<int> store(N, 0);
        int value = N-1;
        
        for(int i = 1; i<N; i++){
            store[p[i]]++;
            store[i]++;
        }
        int edges = 0;
        
        for(auto i : store) if(i == 1) value--;
        
        if(value < 0) return 0;
        
       
        return value;
        
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends