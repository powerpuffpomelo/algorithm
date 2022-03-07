// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        int n = s.size();
        string temp, ans;
        while(j < n){
            while(j < n && s[j] != ' ') j++;
            temp = s.substr(i, j - i);
            reverse(temp.begin(), temp.end());
            ans += ' ' + temp;
            j++;
            i = j;
        }
        return ans.substr(1);
    }
};

// ###################################################### 版本2 ###################################################### //
// 原地修改
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = 0, j = 0;
        while(j < len){
            while(j < len && s[j] != ' ') j++;
            int left = i, right = j - 1;
            while(left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while(j < len && s[j] == ' ') j++;
            i = j;
        }
        return s;
    }
};