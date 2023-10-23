//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string a, int n) { 

        string b = a;
        reverse(a.begin(), a.end());
        int m = b.length();
        vector<int> curr(n+1, 0), prev(n+1, 0);
        for(int i = 0; i<=n; i++) prev[0] = 0;

        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<= m; j++){
                if(a[i - 1] == b[j - 1]) curr[j] =  1 + prev[j - 1];
        
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return a.length() - prev[m];

} 