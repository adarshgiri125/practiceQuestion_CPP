//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    queue<tuple<int,int,int> > q;
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i<m; i++){
        q.push(make_tuple(0, i, mat[0][i]));
    }
    for(int i = 1; i<n; i++){
        q.push(make_tuple(i,0,mat[i][0]));
    }
    
    while(!q.empty()){
        tuple<int, int, int> current = q.front();
        q.pop();
        int i = get<0>(current);
        int j = get<1>(current);
        int val = get<2>(current);
        
        int newr = i + 1;
        int newc = j + 1;
        
        if (newr < n && newc < m) {
            int newval = mat[newr][newc];
            if (val != newval) {
                return false;
            }
            q.push(make_tuple(newr, newc, newval));
        }
    }
    return true;
}