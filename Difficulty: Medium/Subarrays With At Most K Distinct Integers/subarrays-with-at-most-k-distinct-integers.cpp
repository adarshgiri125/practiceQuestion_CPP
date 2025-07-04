class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int l = 0;
        int n = arr.size();
        int distinct_count = 0;
        int not_distinct_subarr = 0;

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            
            if (mp[arr[i]] == 1)    distinct_count++;
            
            while (distinct_count > k) {
                not_distinct_subarr += (n - i);
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)    distinct_count--;
                l++;
            }
        }

        return ((n * (n + 1)) / 2) - not_distinct_subarr;
    }
};