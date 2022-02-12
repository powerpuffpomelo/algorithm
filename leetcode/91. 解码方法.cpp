// todo
class Solution {
public:
    unordered_set<string> hash;
    int numDecodings(string s) {
        int n = s.size();
        for(int i = 1; i <= 26; i++){
            hash.insert(to_string(i));
        }
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(hash.count(s.substr(i, 1))){
                dp[i] += i ? dp[i - 1] : 1;
            }
            if(i >= 1 && hash.count(s.substr(i - 1, 2))){
                dp[i] += i > 1 ? dp[i - 2] : 1;
            }
        }
        return dp[n - 1];
    }
};