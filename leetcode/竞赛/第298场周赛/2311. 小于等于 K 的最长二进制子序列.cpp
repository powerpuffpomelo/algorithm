// ###################################################### 版本1 ###################################################### //
// 贪心
class Solution {
public:
    int longestSubsequence(string s, int k) {
        string t;
        while(k) t += to_string(k % 2), k /= 2;
        reverse(t.begin(), t.end());
        int n = s.size(), m = t.size();
        if(n < m) return n;
        int ans = m - 1;
        for(int i = 0; i < n - (m - 1); i++){
            if(s[i] == '0') ans++;
        }
        if(s.substr(n - m) <= t){
            int cnt = 0;
            for(int i = 0; i < n - m; i++){
                if(s[i] == '0') cnt++;
            }
            ans = max(ans, cnt + m);
        }
        return ans;
    }
};