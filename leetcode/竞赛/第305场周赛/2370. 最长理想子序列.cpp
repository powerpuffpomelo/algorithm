// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    map<char, int> ma;
    int ans = 0;
    int longestIdealString(string s, int k) {
        for(int i = 0; i < 26; i++) ma[i + 'a'] = 0;
        for(char c : s){
            int temp = 1;
            for(int i = 0; i <= k; i++){
                if(c + i >= 'a' && c + i <= 'z') temp = max(temp, ma[c + i] + 1);
                if(c - i >= 'a' && c - i <= 'z') temp = max(temp, ma[c - i] + 1);
                ma[c] = max(ma[c], temp);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};