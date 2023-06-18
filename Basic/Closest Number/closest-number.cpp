//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int n , int m) {
        int num = abs(n);
        int num2 = abs(n);
        // cout<< num % m << endl; 
        while(num % m != 0){
            num--;
        }
        // cout<< num2 % m << endl; 
        while(num2 % m != 0){
            num2++;
        }
        
        
        int value1 = abs(abs(n) - num);
        int value2 = abs(abs(n) - num2);
        if(value1 < value2 && num != 0){
            return num * (n/abs(n));
        }
        else if(value2 < value1){
            return num2 * (n/abs(n));
        }
        else if(value1 == value2){
            return num2 * (n/abs(n));
        }
        else return 0;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends