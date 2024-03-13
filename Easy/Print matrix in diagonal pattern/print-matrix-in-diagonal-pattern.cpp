//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
                int m = mat.size(), n = mat[0].size();
                map<int, vector<int>> mp;
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        mp[i+j].push_back(mat[i][j]);
                    }
                }
                vector<int> res;
                bool flag = true;
                for(auto e: mp){
                    vector<int> v = e.second;
                    if(flag==true) reverse(v.begin(), v.end());
                    for(int i=0;i<v.size();i++) res.push_back(v[i]);
                    flag = !flag;            
                }
        
                return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends