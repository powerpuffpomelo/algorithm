class Solution {
public:
    string reverseWords(string s) {
        vector<string> vv;
        for(int i = 0, j = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                if(i != j) vv.push_back(s.substr(j, i - j));
                j = i + 1;
            }
        }
        reverse(vv.begin(), vv.end());
        string ans;
        for(auto str : vv) ans += str + ' ';
        ans.pop_back();
        return ans;
    }
};