// ###################################################### 版本2 ###################################################### //
// 空间复杂度O(1)
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        reverse(s.begin(), s.end());
        for(int i = 0, j = 0; i <= s.size(); i++){
            while(i < s.size() && s[i] == ' ') i++;
            j = i;
            if(j == s.size()) break;
            while(i < s.size() && s[i] != ' ') i++;
            reverse(s.begin() + j, s.begin() + i);
            if(k) s[k++] = ' ';
            while(j < i) s[k++] = s[j++];
        }
        return s.substr(0, k);
    }
};

// ###################################################### 版本1 ###################################################### //
// 
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