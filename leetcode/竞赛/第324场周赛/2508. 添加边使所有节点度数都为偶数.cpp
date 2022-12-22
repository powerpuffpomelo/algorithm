// ###################################################### 版本1 ###################################################### //
// 
typedef long long LL;

class Solution {
public:
    LL get(int a, int b){
        if(a > b) swap(a, b);
        return a * 1000000ll + b;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_set<LL> se;   // 集合存边
        vector<int> d(n + 1);   // 存每个点的度数
        for(auto e : edges){
            d[e[0]]++, d[e[1]]++;
            se.insert(get(e[0], e[1]));
        }
        vector<int> vs;   // 点度为奇数的点
        for(int i = 1; i <= n; i++){
            if(d[i] % 2) vs.push_back(i);
        }
        if(vs.size() == 0) return true;
        else if(vs.size() == 2){
            int a = vs[0], b = vs[1];
            if(!se.count(get(a, b))) return true;
            for(int i = 1; i <= n; i++){
                if(i != a && i != b && !se.count(get(a, i)) && !se.count(get(b, i))) return true;
            }
        }else if(vs.size() == 4){
            for(int i = 0; i < 24; i++){
                int a = vs[0], b = vs[1], c = vs[2], d = vs[3];
                if(!se.count(get(a, b)) && !se.count(get(c, d))) return true;
                next_permutation(vs.begin(), vs.end());
            }
        }
        return false;
    }
};