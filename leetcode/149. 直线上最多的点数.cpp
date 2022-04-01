// ###################################################### 版本1 ###################################################### //
// 记录斜率分子分母dydx
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