// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int cal(string s, int l, int r){
        if(l + 1 == r) return 1;
        int ans = 0;
        for(int i = l; i <= r; i++){
            int j = i + 1, sum = 1;
            while(sum > 0){
                if(s[j] == '(') sum++;
                else sum--;
                j++;
            }
            if(i + 2 == j) ans++;
            else ans += 2 * cal(s, i + 1, j - 2);
            i = j - 1;
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        return cal(s, 0, s.size() - 1);
    }
};
