// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    map<string, int> cal(string formula){
        map<string, int> cnt;
        for(int i = 0; i < formula.size();){
            if(formula[i] >= 'A' && formula[i] <= 'Z'){
                string elem;
                elem += formula[i];
                int u = i + 1;
                while(u < formula.size() && formula[u] >= 'a' && formula[u] <= 'z'){
                    elem += formula[u++];
                }
                int num = 0;
                while(u < formula.size() && formula[u] >= '0' && formula[u] <= '9'){
                    num = num * 10 + formula[u++] - '0';
                }
                if(!num) num = 1;
                cnt[elem] += num;
                i = u;
            }else{
                int u = i + 1, s = 1;
                while(s){
                    if(formula[u] == '(') s++;
                    else if(formula[u] == ')') s--;
                    u++;
                }
                map<string, int> temp = cal(formula.substr(i + 1, u - i - 2));
                int num = 0;
                while(u < formula.size() && formula[u] >= '0' && formula[u] <= '9'){
                    num = num * 10 + formula[u++] - '0';
                }
                if(!num) num = 1;
                for(auto [k, v] : temp){
                    cnt[k] += v * num;
                }
                i = u;
            }
        }
        return cnt;
    }

    string countOfAtoms(string formula) {
        auto cnt = cal(formula);
        string ans;
        for(auto [k,v] : cnt){
            ans += k;
            if(v > 1) ans += to_string(v);
        }
        return ans;
    }
};