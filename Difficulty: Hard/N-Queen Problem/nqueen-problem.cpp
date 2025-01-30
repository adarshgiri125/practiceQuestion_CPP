//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int row,int n, vector<int> temp, vector<vector<int>> &res,vector<int> &upCol,vector<int> &rightDiag,vector<int> &leftDiag){
        if(row==n){
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(upCol[i]==0 && leftDiag[n-1+row-i]==0 && rightDiag[row+i]==0){
                upCol[i]=1;
                leftDiag[n-1+row-i]=1 ;
                rightDiag[row+i]=1;
                temp.push_back(i+1);
                solve(row+1,n,temp,res,upCol,rightDiag,leftDiag);
                upCol[i]=0;
                leftDiag[n-1+row-i]=0 ;
                rightDiag[row+i]=0;
                  temp.pop_back();
            }
        }
        
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        
         vector<int> upCol(n, 0), rightDiag(2 * n - 1, 0), leftDiag(2 * n - 1, 0);
        
        solve(0,n,temp,res,upCol,rightDiag,leftDiag);
         
         return res;
        
    }

bool check(int row,int col,vector<vector<int>> grid){
        int n= grid.size();
        //check col
        for(int i=0;i<row;i++){
            if(grid[i][col]==1)
            return false;
        }
        
        //check left diagonally
        int r=row-1,c=col-1;
        while(r>=0 && c>=0){
            if(grid[r][c]==1)
            return false;
            
            r--;
            c--;
        }
        
        //right diagonally
         r=row-1,c=col+1;
        while(r>=0 && c<n){
            if(grid[r][c]==1)
            return false;
            
            r--;
            c++;
        }
        
        return true;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends