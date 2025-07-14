class Solution {
  private:
    unordered_set<long> selectedSet;
    int maxi;

    int helper(int ind, string s, int n){
        if(ind == n) return 0;              // ✅ Reached end — no more cuts needed
        if(s[ind] == '0') return 32;        // ❌ Invalid — can't start with 0

        int ans = 32;
        long curr = 0;

        for(int i = ind; i < n; i++){
            curr = (curr << 1) + (s[i] - '0'); // 🔄 Binary to decimal conversion
            if(selectedSet.count(curr)){       // ✅ Check if power of 5
                ans = min(ans, 1 + helper(i + 1, s, n));
            }
        }
        return ans;
    }

  public:
    Solution(){
        maxi = INT_MAX;
        for(long i = 1; i < maxi; i *= 5){
            selectedSet.insert(i);  // 🧠 Precompute all powers of 5
        }
    }

    int cuts(string s) {
        int n = s.size();
        int ans = helper(0, s, n);
        if(ans >= 32) return -1;
        return ans;
    }
};