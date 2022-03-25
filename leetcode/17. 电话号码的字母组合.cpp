// ###################################################### 版本2 ###################################################### //
// 数组方便一些
class Solution {
public:
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs","tuv", "wxyz",
    };
    void dfs(string& digits, int u, string str){
        if(u == digits.size()){
            ans.push_back(str);
            return;
        }
        int x = digits[u] - '0';
        for(char c : strs[x]){
            dfs(digits, u + 1, str + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return ans;
        dfs(digits, 0, "");
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    vector<string> ans;
    unordered_map<int, string> ma;
    void dfs(string& digits, int u, string str){
        if(u == digits.size()){
            ans.push_back(str);
            return;
        }
        int x = digits[u] - '0';
        for(char c : ma[x]){
            dfs(digits, u + 1, str + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return ans;
        ma[2] = "abc";
        ma[3] = "def";
        ma[4] = "ghi";
        ma[5] = "jkl";
        ma[6] = "mno";
        ma[7] = "pqrs";
        ma[8] = "tuv";
        ma[9] = "wxyz";
        dfs(digits, 0, "");
        return ans;
    }
};