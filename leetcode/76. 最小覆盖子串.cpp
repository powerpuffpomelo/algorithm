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