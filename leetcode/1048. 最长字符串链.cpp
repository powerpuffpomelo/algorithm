// ###################################################### 版本2 ###################################################### //
class Solution {
public:
    bool check(string& a, string& b){  // 判断a是b的前身
        if(a.size() + 1 != b.size()) return false;
        int i = 0;
        for(auto c : b){
            if(i < a.size() && a[i] == c) i++;  // 判断子序列
        }
        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b){  // lambda表达式
            return a.size() < b.size();
        });
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(check(words[j], words[i])) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(string& a, string& b){
        return a.size() < b.size();
    }
    bool check(string& a, string& b){
        if(a.size() - b.size() != 1) return false;
        int i = 0, j = 0;
        for(; i < a.size() && j < b.size();){
            if(a[i] != b[j]) i++;
            else i++, j++;
        }
        if(i >= a.size() - 1 && j == b.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n + 1, 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(check(words[i - 1], words[j - 1])) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
            // cout << dp[i] << ' ';
        }
        return ans;
    }
};