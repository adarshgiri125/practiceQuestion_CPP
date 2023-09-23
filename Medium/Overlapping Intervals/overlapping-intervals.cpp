//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        stack<pair<int, int>> s;
        s.push({intervals[0][0], intervals[0][1]});
        
        for (int i = 1; i < intervals.size(); i++) {
            int start1 = s.top().first;
            int end1 = s.top().second;
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            
            if (end1 < start2) {
                s.push({start2, end2});
            } else {
                s.pop();
                end1 = max(end1, end2);
                s.push({start1, end1}); 
            }
        }
        
        while (!s.empty()) {
            ans.push_back({s.top().first, s.top().second});
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends