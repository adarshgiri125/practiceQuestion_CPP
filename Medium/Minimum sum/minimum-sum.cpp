//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
          string ans = "";
          sort(arr,arr+n);
          string lsum;
          string rsum;
          
          for(int i = 0; i<n;){
              char x = arr[i] + '0';
              lsum += x;
              i += 2;
          }
          
           for(int i = 1; i<n;){
              char x = arr[i] + '0';
              rsum += x;
              i += 2;
          }
          
          int n1 = lsum.length();
          int n2 = rsum.length();
          int i = n1-1;
          int j = n2-1;
          string final = "";
          int carry = 0;
          while(j >= 0 && i >= 0){
              int c =  lsum[i] - '0';
              int d = rsum[j] - '0';
              
              int value = c + d + carry;
              carry = 0;
              
              if(value >= 10){
                value = value - 10;
                carry = 1;
              }
              final += value + '0';
              
              i--;
              j--;
          }
          while(i >= 0){
               int c =  lsum[i] - '0';
               
               int value = c + carry;
               carry = 0;
               
               if(value >= 10){
                    value = value - 10;
                    carry = 1;
               }
               
               final += value + '0';
               i--;
               
          }
          
          while(j >= 0){
               int d =  rsum[i] - '0';
               
               int value = d + carry;
               carry = 0;
               
               if(value >= 10){
                    value = value - 10;
                    carry = 1;
               }
               
               final += value + '0';
               j--;
               
          }
          
          if(carry > 0){
              final += carry + '0';
          }
        //   cout << lsum << " " << rsum << endl;
          reverse(final.begin(), final.end());
          int k = 0;
          while(final[k] == '0' && final.length() > 1){
              
              final.erase(final.begin() + k);
          }
         
          
          return final;
          
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends