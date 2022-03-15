// ###################################################### 版本1 ###################################################### //
// 滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht; // 两个哈希表
        for(auto c : t) ht[c]++;
        int cnt = 0;  // cnt记录符合条件的字符数
        string res;
        for(int i = 0, j = 0; s[j]; j++){
            hs[s[j]]++;
            if(hs[s[j]] <= ht[s[j]]) cnt++;
            while(hs[s[i]] > ht[s[i]]) hs[s[i++]]--;
            if(cnt == t.size()){
                if(res.empty() || j - i + 1 < res.size()){
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};

// ###################################################### 版本2 ###################################################### //
// 时隔两个月的思路
class Solution {
public:
    unordered_map<char, int> cnt_t, cnt_s;
    string minWindow(string s, string t) {
        int diff = t.size();
        for(char c : t) cnt_t[c]++;
        string ans = "";
        int i = 0, j = 0;
        for(; j < s.size(); j++){
            char c = s[j];
            cnt_s[c]++;
            if(cnt_s[c] <= cnt_t[c]) diff--;
            while(cnt_s[s[i]] - cnt_t[s[i]] > 0){
                cnt_s[s[i]]--;
                i++;
            }
            if(diff == 0 && (!ans.size() || j - i + 1 < ans.size())) ans = s.substr(i, j - i + 1);
        }
        return ans;
    }
};