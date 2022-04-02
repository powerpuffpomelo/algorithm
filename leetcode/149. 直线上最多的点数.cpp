// ###################################################### 版本3 ###################################################### //
// 键为string
class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int same = 0;
            unordered_map<string, int> cnt;
            for(int j = i + 1; j < n; j++){
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if(!dx && !dy) same++;
                else{
                    if(!dx) dy = 1;
                    if(!dy) dx = 1;
                    else{
                        int g = gcd(dx, dy);
                        dx /= g, dy /= g;
                        if(dy < 0) dx = -dx, dy = -dy;
                    }
                    cnt[to_string(dx) + '_' + to_string(dy)]++;
                }
            }
            int s = 0;
            for(auto [k, t] : cnt) s = max(s, t);
            ans = max(ans, s + same + 1);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 键为long double，边界条件单独计算即可
class Solution {
public:
    typedef long double LD;
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(auto& p : points){
            int ss = 0, vs = 0;   // ss和vs分别代表，相同的，垂直的
            unordered_map<LD, int> cnt;
            for(auto& q : points){
                if(q == p) ss++;
                else if(q[0] == p[0]) vs++;
                else{
                    LD slope = (LD)(q[1] - p[1]) / (q[0] - p[0]);   // 这里必须用long double否则报错，double精度不够
                    cnt[slope]++;
                }
            }
            int c = vs;
            for(auto [k, t] : cnt) c = max(c, t);
            ans = max(ans, c + ss);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 键为pair，记录斜率分子分母dydx
class Solution {
public:
    typedef pair<int, int> pii;
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(!n) return 0;
        sort(points.begin(), points.end());
        int ans = 1;
        for(int i = 0; i < n; i++){
            map<pii, int> cnt;     // pair可以作为map的键，不能作为unordered_map的键
            int same = 0;
            for(int j = i + 1; j < n; j++){
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]){
                    same++;
                    continue;
                }
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if(dy && dx){
                    int divide = gcd(dy, dx);
                    dy /= divide;
                    dx /= divide;
                }else if(dy) dy = 1;
                else if(dx) dx = 1;
                if(dy < 0) dx = -dx, dy = -dy;
                cnt[{dx, dy}]++;
                ans = max(ans, cnt[{dx, dy}] + 1 + same);
            }
        }
        return ans;
    }
};