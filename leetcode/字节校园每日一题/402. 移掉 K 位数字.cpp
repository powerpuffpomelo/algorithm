// 有逆序删逆序，没删完倒着删
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(int i = 0; i < num.size(); i++){
            while(k && i && num[i] < ans.back()){
                ans.pop_back();
                k--;
            }
            ans += num[i];
        }
        if(k) ans = ans.substr(0, ans.size() - k);
        int i = 0;
        while(ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        else ans = ans.substr(i);
        return ans;
    }
};