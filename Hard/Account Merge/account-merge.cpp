//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> parent, size, rank;
public:    
    DisjointSet(int n = 0){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; ++i){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node)return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        if(parU == parV)return;
        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }else if(rank[parV] < rank[parU]){
            parent[parV] = parU;
        }else{
            parent[parV] = parU;
            rank[parU]++;
        }
    }
    void unionBySize(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        if(parU == parV)return;
        if(size[parU] < size[parV]){
            parent[parU] = parV;
            size[parV] += parU;
        }else{
            parent[parV] = parU;
            size[parU] += parV;
        }
    }
};


/*
Given each row(A/C details a number(par) same as index)
stored the mail with the number associated in a map
if a mail found having different row number(par) it means we have to union
eg:
{"John", "j1@com", "j2@com", "j3@com"} -> 0
{"John", "j4@com"} -> 1
{"raj", "r1@com", "r2@com"} -> 2
{"John", "j1@com", "j5@com"} -> 3
{"raj", "r2@com", "r3@com"} -> 4
{"Marry", "m1@com"} -> 5

when par will be 3 we will find j1@com to have a already existing par with value 0
so we will union (0)<-(3)
NOTE although after this we will encounter j5@com, and we are marking its parent as 3 in the map
it wont matter as while finding the parent later we will find the ultimate parent as 0 only
*/

class Solution{
  public:
    // T.C: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E))
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        DisjointSet ds(n);
        int par = 0;
        for(vector<string> &x : accounts){
            for(int i=1; i<x.size(); ++i){
                string mail = x[i];
                if(mp.find(mail) != mp.end()){
                    ds.unionBySize(par, mp[mail]);
                }else{
                    mp[mail] = par;
                }
            }
            par++;
        }
        vector<string> mergedMail[n];
        for(auto it: mp){
            string mail = it.first;
            int parNode = ds.findParent(it.second);
            mergedMail[parNode].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; ++i){
            if(mergedMail[i].size() == 0)continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &x : mergedMail[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends