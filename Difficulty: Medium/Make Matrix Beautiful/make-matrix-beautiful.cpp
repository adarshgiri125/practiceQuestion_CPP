class Solution {
  public:
    int balanceSums(vector<vector<int>>& arr) {
        int n=arr.size(),mx=INT_MIN,ans=0;
        for(int i=0;i<n;++i){
            int s1=0,s2=0;
            for(int j=0;j<n;++j){
                s1 += arr[i][j];
                s2 += arr[j][i];
            }
            mx=max(mx,max(s2,s1));
        }
        for(int i=0;i<n;++i){
            int s=0;
            for(int j=0;j<n;++j)
            s += arr[i][j];
            ans += (mx-s);
        }
        return ans;
    }
};