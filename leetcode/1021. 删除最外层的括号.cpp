// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        for(int i = 0, j = 0, cnt = 0; i < s.size(); i++){
            if(s[i] == '('){
                cnt++;
            }else if(--cnt == 0){
                ans += s.substr(j + 1, i - j - 1);
                j = i + 1;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans, temp;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            temp += s[i];
            if(s[i] == '(') cnt++;
            else cnt--;
            if(!cnt){
                ans += temp.substr(1, temp.size() - 2);
                temp = "";
            }
        }
        return ans;
    }
};