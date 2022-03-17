// ###################################################### 版本1 ###################################################### //
// 递归，每层括号里字符串展开
class Solution {
public:
    string decodeString(string s) {
        string ret;
        for(int i = 0; i < s.size();){
            if(!isdigit(s[i])) ret += s[i++];
            else{
                int j = i;
                while(isdigit(s[j])) j++;
                int k = stoi(s.substr(i, j - i));
                int u = j + 1, sum = 0;
                while(sum >= 0){
                    if(s[u] == '[') sum++;
                    else if(s[u] == ']') sum--;
                    u++;
                }
                string temp = decodeString(s.substr(j + 1, u - j - 2));
                while(k--) ret += temp;
                i = u;
            }
        }
        return ret;
    }
};