// ###################################################### 版本1 ###################################################### //
// 扫描线
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;
        multiset<int> heights;  // multiset自动排序，且方便插入删除；之所以不用堆是因为堆无法删除
        for(auto& b : buildings){
            points.push_back({b[0], -b[2]});  // 左端点相同，要把大的排前边
            points.push_back({b[1], b[2]});   // 右端点相同，要把小的排前边
        }
        sort(points.begin(), points.end());
        heights.insert(0);
        for(auto p : points){
            int x = p.first, h = abs(p.second);
            if(p.second < 0){   // 左端点
                if(h > *heights.rbegin()) ans.push_back({x, h});
                heights.insert(h);
            }else{     // 右端点
                heights.erase(heights.find(h));   // 要用find才能只删一个，如果直接erase一个值的话，multiset会把所有等于这个值的元素都删除
                if(h > *heights.rbegin()) ans.push_back({x, *heights.rbegin()});
            }
        }
        return ans;
    }
};