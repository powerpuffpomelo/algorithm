class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for(char c : s) cnt[c]++;
        int ans = 0, have = 0;
        for(auto [k, v] : cnt){
            ans += v / 2 * 2;
            if(v % 2) have = 1;
        }
        return ans + have;
    }
};