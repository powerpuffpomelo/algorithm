// ###################################################### 版本2 ###################################################### //
// 优化写法
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){  // 匿名函数
            return a[1] < b[1];
        });
        int ans = 1, r = points[0][1];
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] > r){
                ans++;
                r = points[i][1];
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){    // cmp要传引用，否则tle
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 1, last = points[0][1], p = 0;
        while(p < points.size()){
            while(p < points.size() && points[p][0] <= last && points[p][1] >= last) p++;
            if(p < points.size()){
                last = points[p][1];
                ans++;
            }
        }
        return ans;
    }
};