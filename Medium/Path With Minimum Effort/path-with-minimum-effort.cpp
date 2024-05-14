//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
   using my_tuple = tuple<int, int, int>;
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
       priority_queue<my_tuple, vector<my_tuple>, greater<my_tuple>> pq;
        
        pq.push(make_tuple(0,0,0));
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
         dist[0][0] = 0;
        
        while(!pq.empty()){
            int d, r, c;
            tie(d, r, c) = pq.top();

            if(r == n-1 && c == m-1){
                return d;
            }
            pq.pop();
            
            for(int i = 0; i<4; i++){
                
                int newr = r + dx[i];
                int newc = c + dy[i];
                 if(newr >= 0 && newc >= 0 && newr < n && newc < m){
                    int newEffort = max(abs(heights[newr][newc] - heights[r][c]), d);
                  
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push(make_tuple(newEffort, newr, newc));
                    }
                } 
            }
    
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends