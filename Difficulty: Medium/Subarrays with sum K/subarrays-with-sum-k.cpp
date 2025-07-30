class Solution {
  public:
     int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int s=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            s+=arr[i];
            if(mp.find(s-k)!=mp.end())ans+=mp[s-k];
            mp[s]++;
        }
        return ans;
    }
};