// ###################################################### 版本1 ###################################################### //
// 我的初版
// TODO 优化
class Solution {
public:
    string find(string s, unordered_map<string, string>& p){
        if(!p.count(s)) p[s] = s;
        if(p[s] != s) p[s] = find(p[s], p);
        return p[s];
    }
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string, int> cnt;
        unordered_map<string, string> p;
        for(auto s : names){
            int i = 0;
            while(s[i] != '(') i++;
            string num = s.substr(i + 1);
            num.pop_back();
            cnt[s.substr(0, i)] = stoi(num);
            p[s.substr(0, i)] = s.substr(0, i);
        }
        for(auto s : synonyms){
            int i = 0;
            while(s[i] != ',') i++;
            string a = s.substr(1, i - 1), b = s.substr(i + 1);
            b.pop_back();
            string pa = find(a, p), pb = find(b, p);
            if(pa <= pb){
                p[pb] = pa;
            }else{
                p[pa] = pb;
            }
        }
        for(auto [k, v] : cnt){
            string r = find(k, p);
            if(r != k){
                if(!cnt.count(r)) cnt[r] = 0;
                cnt[r] += v;
                cnt[k] = 0;
            }
        }
        vector<string> ans;
        for(auto [k, v] : cnt){
            if(v == 0) continue;
            string s = k + '(' + to_string(v) + ')';
            ans.push_back(s);
        }
        return ans;
    }
};