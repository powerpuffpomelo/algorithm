// ###################################################### 版本2 ###################################################### //
// yxc
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ret = 0;
        for(int i = 0, j = 0; i < s.size(); i++){
            hash[s[i]]++;
            while(hash[s[i]] > 1){
                hash[s[j++]]--;
            }
            ret = max(ret, i - j + 1);
        }
        return ret;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int i = 0, j = 0;
        int ret = 0;
        unordered_map<char, int> hash;
        while(s[j]){
            if(!hash[s[j]]){
                hash[s[j]] = 1;
                j++;
                ret = max(ret, j - i);
            }else{
                while(s[i] != s[j]){
                    hash[s[i]] = 0;
                    i++;
                }
                i++;
                j++;
            }
        }
        return ret;
    }
};

