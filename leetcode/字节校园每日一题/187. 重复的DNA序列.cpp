// ###################################################### 版本2 ###################################################### //
// 优化一点点写法
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> ma;
        for(int i = 0; i + 10 - 1 < s.size(); i++){
            string str = s.substr(i, 10);
            if(ma[str] == 1) ans.push_back(str);
            ma[str] += 1;
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// map遍历
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> ma;
        for(int i = 0; i + 10 - 1 < s.size(); i++){
            string str = s.substr(i, 10);
            ma[str]++;
        }
        vector<string> ans;
        for(auto [k, v] : ma){
            if(v > 1) ans.push_back(k);
        }
        return ans;
    }
};

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