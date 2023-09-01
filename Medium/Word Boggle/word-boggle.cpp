//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

//     bool dfs(int row, int col,int ind,string &word, vector<vector<char>>& board, vector<string>& dict, vector<vector<int>>& vis) {
//         int n = board.size();
//         if (ind == word.size()) {
//             return true;
//         }
//         vis[row][col] = 1;
    
     
    
//         for (int i = -1; i <= 1; i++) {
//             for (int j = -1; j <= 1; j++) {
//                 int nrow = row + i;
//                 int ncol = col + j;
    
//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] &&
//                     board[nrow][ncol] == word[ind]) {
//                     vis[nrow][ncol] = 1;
//                     if(dfs(nrow, ncol, ind + 1,word, board, dict, vis)) return true;
                    
//                 }
//             }
           
//         }
        
//         vis[row][col] = 0;
//         return false;
    
       
//     }

// 	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
// 	    vector<string> ans;
	    
// 	    int n = board.size();
	    
// 	    for(int k = 0; k<dict.size(); k++){
// 	           bool check = false;
//     	    for(int i = 0; i<n; i++){
//     	        for(int j = 0; j<n; j++){
    	            
	                
// 	                vector<vector<int> > vis(n,vector<int> (n,0));
// 	                if(board[i][j] == dict[k][0]&& !vis[i][j] && dfs(i,j,1,dict[k],board,dict,vis) == true){
// 	                        ans.push_back(dict[k]);
// 	                        check = true;
// 	                        break;
// 	                }
	                 
//     	        }
//     	        if(check) break;
//     	    }
// 	    }
	    
	   
// 	    return ans;
// 	}
    bool dfs(int row, int col,int ind, vector<vector<char> >& board, string &word,
    vector<vector<int>> &vis) {
        if(ind == word.size()) {
            return true; 
        }
        int n = board.size(), m = board[0].size(); 
        vis[row][col] = 1; 
        
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; 
        
        for(int i = 0; i < 8; i++) {
            int nrow = row + dx[i]; 
            int ncol = col + dy[i]; 
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && 
            board[nrow][ncol] == word[ind]) {
                if(dfs(nrow, ncol, ind+1, board, word, vis) == true)
                    return true;  
            }
        }
        
        vis[row][col] = 0; 
        return false; 
    }
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
        vector<string> ans; 
        int n = board.size(), m = board[0].size(); 
        
        for(int d = 0; d < dict.size(); d++) {
            bool flag = true; 
            vector<vector<int>> vis(n, vector<int> (m, 0)); 
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j] == dict[d][0] && !vis[i][j]
                    && dfs(i, j, 1, board, dict[d], vis) == true) {
                        ans.push_back(dict[d]); 
                        flag = false; 
                        break; 
                    }
                }
                if(flag == false) 
                    break; 
            }
        }
        return ans; 
    }
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends