// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_set<string> se, ans;
        if(s.size() < 10) return ret;
        string str = s.substr(0, 10);
        se.insert(str);
        for(int i = 1; i + 10 - 1 < s.size(); i++){
            str = str.substr(1);
            str += s[i + 10 - 1];
            if(se.count(str)){
                ans.insert(str);
            }
            se.insert(str);
        }
        for(auto str : ans) ret.push_back(str);
        return ret;
    }
};