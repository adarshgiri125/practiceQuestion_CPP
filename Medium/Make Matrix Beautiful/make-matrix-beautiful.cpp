//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int rowSum = 0;
        int colSum = 0;
        
        for(int i = 0; i<n; i++){
               int col = 0;
               int row = 0;
            for(int j = 0; j<n; j++){
                col += matrix[i][j];
                colSum = max(col,colSum);
                
                row += matrix[j][i];
                rowSum = max(row,rowSum);
                
            }
        }
        int value = max(rowSum,colSum);
       
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                sum += matrix[i][j];
            }
            if(sum < value){
                 ans += value - sum;
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends