// ###################################################### 版本1 ###################################################### //
// 分类讨论
class Solution {
public:
    int dis(int x1, int y1, int x2, int y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool checkOverlap(int radius, int a, int b, int x1, int y1, int x2, int y2) {
        int r2 = radius * radius;
        // 判断矩形的四个角重叠
        if(dis(a, b, x1, y1) <= r2 || dis(a, b, x1, y2) <= r2 || dis(a, b, x2, y1) <= r2 || dis(a, b, x2, y2) <= r2) return true;
        // 判断矩形的四条边重叠
        if((abs(y1 - b) <= radius || abs(y2 - b) <= radius) && a >= x1 && a <= x2) return true;
        if((abs(x1 - a) <= radius || abs(x2 - a) <= radius) && b >= y1 && b <= y2) return true;
        // 判断圆心在矩形内
        if(x1 <= a && x2 >= a && y1 <= b && y2 >= b) return true;
        return false;
    }
};