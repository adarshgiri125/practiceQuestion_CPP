//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size() - 1;
        int val = str[n] - '0';

        int diff = 10 - val;
               
        if(diff < 5){
           str[n] = '0';
           if(n == 0) return "10";
           else{
                int i = n - 1;
                int ind = str[i] - '0';
                while (i > 0 && ind == 9) {
                    i--;
                    ind = str[i] - '0';
                }
                if (i == 0 && ind == 9) {
                    int v = (n - i);
                    int val = pow (10,v + 1);
                    return to_string(val);
                }
                
                ind++;
                str[i] = ind + '0';
                for (int j = i + 1; j < n; j++) {
                    str[j] = '0';
                }
                

           }
           return str;
        } 
        else{
            str[n] = '0';
            return str;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends