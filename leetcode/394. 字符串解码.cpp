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

class Solution {
public:
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }
    string dfs(string &s, int &u){
        string ret;
        while(u < s.size() && s[u] != ']'){
            if(!isdigit(s[u])) ret += s[u++];
            else{
                int i = u;
                while(isdigit(s[i])) i++;
                int k = stoi(s.substr(u, i - u));
                u = i + 1;
                string temp = dfs(s, u);
                while(k--) ret += temp;
                u++;
            }
        }
        return ret;
    }
};