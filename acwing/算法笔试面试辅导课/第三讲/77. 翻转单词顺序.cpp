// ###################################################### 版本1 ###################################################### //
// 空间复杂度 O(1) 时间复杂度O(n)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};

// ###################################################### 版本2 ###################################################### //
// 额外数组
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vv;
        int q = s.size() - 1;
        for(int p = s.size() - 2; p >= 0; p--){
            if(s[p] == ' '){
                vv.push_back(s.substr(p + 1, q - p));
                q = p - 1;
            }
        }
        if(q >= 0) vv.push_back(s.substr(0, q + 1));
        string ret = "";
        for(auto ss : vv){
            ret += ss + ' ';
        }
        return ret.substr(0, ret.size() - 1);
    }
};