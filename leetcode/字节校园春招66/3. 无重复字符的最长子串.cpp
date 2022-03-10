class Solution {
public:
    unordered_map<char, int> cnt;
    int ans = 0;
    int lengthOfLongestSubstring(string s) {
        for(int i = 0, j = 0; i < s.size(); i++){
            cnt[s[i]]++;
            while(cnt[s[i]] > 1){
                cnt[s[j++]]--;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};