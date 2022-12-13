// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                for(char c = 'a'; c <= 'z'; c++){
                    if(i && s[i - 1] == c || i < n - 1 && s[i + 1] == c) continue;
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};