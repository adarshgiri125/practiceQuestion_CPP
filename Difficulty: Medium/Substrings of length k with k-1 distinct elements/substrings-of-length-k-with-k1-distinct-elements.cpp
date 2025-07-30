class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char, int> mp;
        //sliding window
        int cnt = 0;
        for(int i=0;i<k;i++){
            mp[s[i]]++;
        }
        if(mp.size() == k-1){
            cnt++;
        }
        int left = 0;
        for(int i=k;i<s.size();i++){
            mp[s[left]]--;
            if(mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            mp[s[i]]++;
            if(mp.size() == k-1){
                cnt++;
            }
            left++;
        }
        return cnt;
    }
};