// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ma;
        for(string s : strs){  // s复制了strs中的每一个字符串，更改s不会更改strs中的字符串
            string tt = s;
            sort(s.begin(), s.end());
            ma[s].push_back(tt);
        } 
        for(auto item : ma) ans.push_back(item.second);
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 传地址：本来需要将整个字符串copy过去，使用move之后只需要把字符串的首地址赋值过去，可以减少一次拷贝操作，提高效率。
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ma;
        for(string &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            ma[key].push_back(move(s));
        }
        for(auto i = ma.begin(); i != ma.end(); i++){
            ans.push_back(move(i->second));
        }
        return ans;
    }
};